#include "parser.h"
#include "symbols.h"
#include "../analyse_lexicale/lexer_common.h"
#include <stdarg.h>

static Token current_token;
static FILE *source_file;
static int current_line = 1;

static ManualSymbolTable *config_table;
static ManualSymbolTable *pipeline_table;
static DataType last_parsed_type;

void get_next_token() {
    int c;
    while ((c = fgetc(source_file)) != EOF) {
        if (c == '\n') current_line++;
        else if (isspace(c)) continue;
        else if (c == '/') {
            int next = fgetc(source_file);
            if (next == '/') {
                while ((c = fgetc(source_file)) != EOF && c != '\n');
                current_line++;
                continue;
            } else {
                ungetc(next, source_file);
                break;
            }
        } else break;
    }

    if (c == EOF) {
        current_token.type = TOK_EOF;
        return;
    }

    char buffer[1024];
    int idx = 0;
    buffer[idx++] = c;

    // Smart greedy match
    if (isalpha(c) || c == '_') {
        while (isalnum(c = fgetc(source_file)) || c == '_') buffer[idx++] = c;
        ungetc(c, source_file);
    } else if (isdigit(c)) {
        int dot = 0;
        while (isdigit(c = fgetc(source_file)) || (c == '.' && !dot)) {
            if (c == '.') dot = 1;
            buffer[idx++] = c;
        }
        ungetc(c, source_file);
    } else if (c == '"') {
        while ((c = fgetc(source_file)) != EOF && c != '"') buffer[idx++] = c;
        buffer[idx++] = '"';
    } else if (strchr("+-*/%=!<>", c)) {
        int next = fgetc(source_file);
        if (next == '=') buffer[idx++] = next;
        else ungetc(next, source_file);
    }

    buffer[idx] = '\0';
    strcpy(current_token.lexeme, buffer);
    current_token.type = scan_token(buffer);
    current_token.line = current_line;
}

void error(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "PARSER ERROR (Line %d): ", current_token.line);
    vfprintf(stderr, fmt, args);
    fprintf(stderr, " (found '%s')\n", current_token.lexeme);
    va_end(args);
    exit(1);
}

void match(TokenType expected) {
    if (current_token.type == expected) {
        get_next_token();
    } else {
        error("Expected different token");
    }
}

// Grammatical rules
void parse_expression();
void parse_statements();

void parse_primary() {
    if (current_token.type == TOK_ID || current_token.type == TOK_INT_LIT || 
        current_token.type == TOK_FLOAT_LIT || current_token.type == TOK_STRING_LIT ||
        current_token.type == TOK_NULL || current_token.type == TOK_VALID || 
        current_token.type == TOK_SUSPECT || current_token.type == TOK_REJECT) {
        get_next_token();
    } else if (current_token.type == TOK_LPAREN) {
        match(TOK_LPAREN);
        parse_expression();
        match(TOK_RPAREN);
    } else {
        error("Expression expected");
    }
}

void parse_expression() {
    parse_primary();
    while (current_token.type == TOK_PLUS || current_token.type == TOK_MINUS || 
           current_token.type == TOK_MULT || current_token.type == TOK_DIV ||
           current_token.type == TOK_EQ || current_token.type == TOK_NEQ ||
           current_token.type == TOK_GE || current_token.type == TOK_LE ||
           current_token.type == TOK_GT || current_token.type == TOK_LT ||
           current_token.type == TOK_CONTAINS || current_token.type == TOK_AND ||
           current_token.type == TOK_OR) {
        get_next_token();
        parse_primary();
    }
}

void parse_block() {
    match(TOK_LBRACE);
    parse_statements();
    match(TOK_RBRACE);
}

void parse_statement() {
    ManualSymbol *s;
    switch(current_token.type) {
        case TOK_IF:
            match(TOK_IF); match(TOK_LPAREN); parse_expression(); match(TOK_RPAREN);
            parse_block();
            if (current_token.type == TOK_ELSE) {
                match(TOK_ELSE); parse_block();
            }
            break;
        case TOK_WHILE:
            match(TOK_WHILE); match(TOK_LPAREN); parse_expression(); match(TOK_RPAREN);
            parse_block();
            break;
        case TOK_SCAN:
            match(TOK_SCAN); 
            s = lookup_manual_symbol(config_table, pipeline_table, current_token.lexeme);
            if (!s) error("Undefined variable in SCAN");
            match(TOK_ID); match(TOK_WITH); 
            s = lookup_manual_symbol(config_table, pipeline_table, current_token.lexeme);
            if (!s) error("Undefined dictionary in SCAN");
            match(TOK_ID);
            parse_block();
            break;
        case TOK_INGEST:
            match(TOK_INGEST); match(TOK_ID); match(TOK_FROM); match(TOK_ID);
            break;
        case TOK_DISPATCH:
            match(TOK_DISPATCH); match(TOK_ID); match(TOK_TO); match(TOK_ID);
            break;
        case TOK_LOG:
            match(TOK_LOG); match(TOK_STRING_LIT); match(TOK_LEVEL); match(TOK_INT_LIT);
            break;
        case TOK_NORMALIZE:
            match(TOK_NORMALIZE); match(TOK_ID);
            break;
        case TOK_MASK:
            match(TOK_MASK); match(TOK_ID); match(TOK_WITH); match(TOK_STRING_LIT);
            break;
        case TOK_ID:
            s = lookup_manual_symbol(config_table, pipeline_table, current_token.lexeme);
            if (!s) error("Undefined variable");
            match(TOK_ID); match(TOK_ASSIGN); parse_expression();
            break;
        case TOK_TYPE_INT: case TOK_TYPE_TEXT: case TOK_TYPE_PROB: 
        case TOK_TYPE_VERDICT: case TOK_TYPE_DICT:
            last_parsed_type = (DataType)(current_token.type - TOK_TYPE_INT); // Simple mapping
            get_next_token(); 
            insert_manual_symbol(pipeline_table, current_token.lexeme, last_parsed_type, 0);
            match(TOK_ID); match(TOK_ASSIGN); parse_expression();
            break;
        default:
            error("Unexpected statement start");
    }
}

void parse_statements() {
    while (current_token.type != TOK_RBRACE && current_token.type != TOK_EOF) {
        parse_statement();
    }
}

void parse_config() {
    match(TOK_CONFIG);
    match(TOK_LBRACE);
    while (current_token.type != TOK_RBRACE) {
        if (current_token.type >= TOK_TYPE_INT && current_token.type <= TOK_TYPE_BATCH) {
            last_parsed_type = (DataType)(current_token.type - TOK_TYPE_INT);
            get_next_token(); // Type
            insert_manual_symbol(config_table, current_token.lexeme, last_parsed_type, 1);
            match(TOK_ID); 
            match(TOK_ASSIGN);
            if (current_token.type == TOK_LBRACKET) {
                match(TOK_LBRACKET);
                while (current_token.type != TOK_RBRACKET) {
                    match(TOK_STRING_LIT);
                    if (current_token.type == TOK_COMMA) match(TOK_COMMA);
                }
                match(TOK_RBRACKET);
            } else {
                parse_expression();
            }
        } else break;
    }
    match(TOK_RBRACE);
}

void parse_pipeline() {
    match(TOK_PIPELINE);
    parse_block();
}

void parse_program() {
    match(TOK_PROCESS);
    match(TOK_STRING_LIT);
    match(TOK_LBRACE);
    parse_config();
    parse_pipeline();
    match(TOK_RBRACE);
    printf("--- Manual Sync/Semantic successful! ---\n");
}

void init_parser(FILE *f) {
    source_file = f;
    config_table = create_manual_table();
    pipeline_table = create_manual_table();
    init_lexer();
    get_next_token();
}
