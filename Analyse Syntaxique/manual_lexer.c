#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* --- 1. TOKEN DEFINITIONS (Based on SENTINEL) --- */
typedef enum {
    TOK_EOF = 0,
    TOK_ERROR,

    // Keywords
    TOK_PROCESS, TOK_CONFIG, TOK_PIPELINE,
    TOK_TYPE_INT, TOK_TYPE_TEXT, TOK_TYPE_PROB, TOK_TYPE_VERDICT, TOK_TYPE_DICT, TOK_TYPE_BATCH,
    TOK_VALID, TOK_SUSPECT, TOK_REJECT,
    TOK_INGEST, TOK_FROM, TOK_DISPATCH, TOK_TO, TOK_LOG, TOK_LEVEL,
    TOK_NORMALIZE, TOK_MASK, TOK_WITH, TOK_SCAN,
    TOK_WHILE, TOK_IF, TOK_ELSE, TOK_NULL,
    TOK_IN, TOK_CONTAINS, TOK_AND, TOK_OR, TOK_NOT,

    // Literals
    TOK_ID, TOK_INT_LIT, TOK_FLOAT_LIT, TOK_STRING_LIT,

    // Operators & Delimiters
    TOK_PLUS, TOK_MINUS, TOK_MULT, TOK_DIV, TOK_MOD, TOK_ASSIGN,
    TOK_EQ, TOK_NEQ, TOK_LT, TOK_GT, TOK_LE, TOK_GE,
    TOK_LBRACE, TOK_RBRACE, TOK_LPAREN, TOK_RPAREN, TOK_LBRACKET, TOK_RBRACKET, TOK_COMMA
} TokenType;

// Helper struct for Keyword Lookup
typedef struct {
    char *name;
    TokenType type;
} KeywordEntry;

const KeywordEntry keywords[] = {
    {"PROCESS", TOK_PROCESS}, {"CONFIG", TOK_CONFIG}, {"PIPELINE", TOK_PIPELINE},
    {"integer", TOK_TYPE_INT}, {"text", TOK_TYPE_TEXT}, {"probability", TOK_TYPE_PROB},
    {"verdict", TOK_TYPE_VERDICT}, {"dictionary", TOK_TYPE_DICT}, {"batch", TOK_TYPE_BATCH},
    {"VALID", TOK_VALID}, {"SUSPECT", TOK_SUSPECT}, {"REJECT", TOK_REJECT},
    {"INGEST", TOK_INGEST}, {"FROM", TOK_FROM}, {"DISPATCH", TOK_DISPATCH},
    {"TO", TOK_TO}, {"LOG", TOK_LOG}, {"LEVEL", TOK_LEVEL},
    {"NORMALIZE", TOK_NORMALIZE}, {"MASK", TOK_MASK}, {"WITH", TOK_WITH},
    {"SCAN", TOK_SCAN}, {"WHILE", TOK_WHILE}, {"IF", TOK_IF},
    {"ELSE", TOK_ELSE}, {"NULL", TOK_NULL},
    {"IN", TOK_IN}, {"CONTAINS", TOK_CONTAINS},
    {"AND", TOK_AND}, {"OR", TOK_OR}, {"NOT", TOK_NOT},
    {NULL, 0}
};

/* --- 2. GLOBAL VARIABLES --- */
FILE *source_file;
int current_line = 1;
char lexeme_buffer[1024]; // Stores the text of the current token

/* --- 3. HELPER FUNCTIONS --- */

// Check if a string is a keyword
TokenType resolve_keyword(const char *str) {
    for (int i = 0; keywords[i].name != NULL; i++) {
        if (strcmp(str, keywords[i].name) == 0) {
            return keywords[i].type;
        }
    }
    return TOK_ID; // Not a keyword, so it's an Identifier
}

// Get name of token for printing
const char* get_token_name(TokenType t) {
    switch(t) {
        // Keywords
        case TOK_PROCESS:   return "KEYWORD_PROCESS";
        case TOK_CONFIG:    return "KEYWORD_CONFIG";
        case TOK_PIPELINE:  return "KEYWORD_PIPELINE";
        
        // Types
        case TOK_TYPE_INT:      return "TYPE_INTEGER";
        case TOK_TYPE_TEXT:     return "TYPE_TEXT";
        case TOK_TYPE_PROB:     return "TYPE_PROBABILITY";
        case TOK_TYPE_VERDICT:  return "TYPE_VERDICT";
        case TOK_TYPE_DICT:     return "TYPE_DICTIONARY";
        case TOK_TYPE_BATCH:    return "TYPE_BATCH";

        // Verdicts
        case TOK_VALID:     return "VERDICT_VALID";
        case TOK_SUSPECT:   return "VERDICT_SUSPECT";
        case TOK_REJECT:    return "VERDICT_REJECT";

        // Instructions
        case TOK_INGEST:    return "INSTRUCTION_INGEST";
        case TOK_FROM:      return "KEYWORD_FROM";
        case TOK_DISPATCH:  return "INSTRUCTION_DISPATCH";
        case TOK_TO:        return "KEYWORD_TO";
        case TOK_LOG:       return "INSTRUCTION_LOG";
        case TOK_LEVEL:     return "KEYWORD_LEVEL";
        case TOK_NORMALIZE: return "INSTRUCTION_NORMALIZE";
        case TOK_MASK:      return "INSTRUCTION_MASK";
        case TOK_WITH:      return "KEYWORD_WITH";
        case TOK_SCAN:      return "INSTRUCTION_SCAN";
        
        // Control Flow
        case TOK_WHILE:     return "CONTROL_WHILE";
        case TOK_IF:        return "CONTROL_IF";
        case TOK_ELSE:      return "CONTROL_ELSE";
        case TOK_NULL:      return "VALUE_NULL";

        // Logic
        case TOK_IN:        return "OP_IN";
        case TOK_CONTAINS:  return "OP_CONTAINS";
        case TOK_AND:       return "OP_AND";
        case TOK_OR:        return "OP_OR";
        case TOK_NOT:       return "OP_NOT";

        // Literals
        case TOK_ID:            return "IDENTIFIER";
        case TOK_INT_LIT:       return "LITERAL_INT";
        case TOK_FLOAT_LIT:     return "LITERAL_PROB";
        case TOK_STRING_LIT:    return "LITERAL_STRING";

        // Operators & Delimiters
        case TOK_PLUS:      return "OP_PLUS '+'";
        case TOK_MINUS:     return "OP_MINUS '-'";
        case TOK_MULT:      return "OP_MULT '*'";
        case TOK_DIV:       return "OP_DIV '/'";
        case TOK_MOD:       return "OP_MOD '%'";
        case TOK_ASSIGN:    return "OP_ASSIGN '='";
        case TOK_EQ:        return "OP_EQUALS '=='";
        case TOK_NEQ:       return "OP_NOT_EQ '!='";
        case TOK_LT:        return "OP_LESS '<'";
        case TOK_GT:        return "OP_GREATER '>'";
        case TOK_LE:        return "OP_LESS_EQ '<='";
        case TOK_GE:        return "OP_GREATER_EQ '>='";
        
        case TOK_LBRACE:    return "LBRACE '{'";
        case TOK_RBRACE:    return "RBRACE '}'";
        case TOK_LPAREN:    return "LPAREN '('";
        case TOK_RPAREN:    return "RPAREN ')'";
        case TOK_LBRACKET:  return "LBRACKET '['";
        case TOK_RBRACKET:  return "RBRACKET ']'";
        case TOK_COMMA:     return "COMMA ','";

        case TOK_EOF:       return "EOF";
        case TOK_ERROR:     return "ERROR";
        default:            return "UNKNOWN_TOKEN";
    }
}



/* --- 4. CORE LEXER LOGIC --- */

TokenType get_next_token() {
    int c;
    int idx = 0;
    lexeme_buffer[0] = '\0';

    // 1. Skip Whitespace and Count Newlines
    while ((c = fgetc(source_file)) != EOF) {
        if (c == '\n') {
            current_line++;
        } else if (!isspace(c)) {
            break; // Found a non-space character
        }
    }

    if (c == EOF) return TOK_EOF;

    // 2. Handle Comments (//)
    if (c == '/') {
        int next = fgetc(source_file);
        if (next == '/') {
            // It is a comment, consume until newline
            while ((c = fgetc(source_file)) != EOF && c != '\n');
            current_line++;
            return get_next_token(); // Recursively call to get the next real token
        } else {
            ungetc(next, source_file); // Not a comment, it's a division '/'
            // Fall through to operator handling
        }
    }

    // 3. Handle Identifiers and Keywords (Starts with Letter)
    if (isalpha(c) || c == '_') {
        lexeme_buffer[idx++] = c;
        while (isalnum(c = fgetc(source_file)) || c == '_') {
            if (idx < 1023) lexeme_buffer[idx++] = c;
        }
        ungetc(c, source_file); // Put back the char that stopped the loop
        lexeme_buffer[idx] = '\0';
        return resolve_keyword(lexeme_buffer);
    }

    // 4. Handle Numbers (Integers and Floats)
    if (isdigit(c)) {
        int is_float = 0;
        lexeme_buffer[idx++] = c;
        while (isdigit(c = fgetc(source_file)) || c == '.') {
            if (c == '.') {
                if (is_float) break; // Second dot? Stop.
                is_float = 1;
            }
            if (idx < 1023) lexeme_buffer[idx++] = c;
        }
        ungetc(c, source_file);
        lexeme_buffer[idx] = '\0';
        return is_float ? TOK_FLOAT_LIT : TOK_INT_LIT;
    }

    // 5. Handle Strings ("...")
    if (c == '"') {
        // Don't include the opening quote in the value? 
        // Usually we keep it for the parser to know, or strip it. Let's keep the content.
        while ((c = fgetc(source_file)) != EOF && c != '"') {
            if (idx < 1023) lexeme_buffer[idx++] = c;
        }
        // c is now '"' or EOF
        lexeme_buffer[idx] = '\0';
        return TOK_STRING_LIT;
    }

    // 6. Handle Operators and Delimiters
    lexeme_buffer[idx++] = c;
    lexeme_buffer[idx] = '\0';

    switch (c) {
        case '{': return TOK_LBRACE;
        case '}': return TOK_RBRACE;
        case '(': return TOK_LPAREN;
        case ')': return TOK_RPAREN;
        case '[': return TOK_LBRACKET;
        case ']': return TOK_RBRACKET;
        case ',': return TOK_COMMA;
        case '+': return TOK_PLUS;
        case '-': return TOK_MINUS;
        case '*': return TOK_MULT;
        case '%': return TOK_MOD;
        
        case '=': 
            if ((c = fgetc(source_file)) == '=') { lexeme_buffer[idx++] = '='; lexeme_buffer[idx] = 0; return TOK_EQ; }
            ungetc(c, source_file); return TOK_ASSIGN;
        
        case '!': 
            if ((c = fgetc(source_file)) == '=') { lexeme_buffer[idx++] = '='; lexeme_buffer[idx] = 0; return TOK_NEQ; }
            ungetc(c, source_file); return TOK_ERROR; // Standalone '!' not supported in SENTINEL
        
        case '<': 
            if ((c = fgetc(source_file)) == '=') { lexeme_buffer[idx++] = '='; lexeme_buffer[idx] = 0; return TOK_LE; }
            ungetc(c, source_file); return TOK_LT;

        case '>': 
            if ((c = fgetc(source_file)) == '=') { lexeme_buffer[idx++] = '='; lexeme_buffer[idx] = 0; return TOK_GE; }
            ungetc(c, source_file); return TOK_GT;
    }

    return TOK_ERROR;
}

/* --- 5. MAIN ENTRY POINT --- */

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    source_file = fopen(argv[1], "r");
    if (!source_file) {
        perror("Error opening file");
        return 1;
    }

    printf("=== SENTINEL MANUAL ANALYSIS START ===\n");
    printf("Analyzing file: %s\n\n", argv[1]);
    printf("%-20s | %-20s | %s\n", "TYPE", "NAME", "VALUE");
    printf("---------------------------------------------------------------\n");

    TokenType token;
    while ((token = get_next_token()) != TOK_EOF) {
        if (token == TOK_ERROR) {
            printf("ERROR at line %d: Unknown character '%s'\n", current_line, lexeme_buffer);
        } else {
            printf("%-20d | %-20s | %s\n", 
                token, 
                get_token_name(token), 
                lexeme_buffer);
        }
    }

    printf("\n=== ANALYSIS COMPLETE ===\n");
    fclose(source_file);
    return 0;
}