#include "lexer_common.h"

typedef struct {
    char *name;
    AFN* afn;
} TokenDefinition;

static TokenDefinition definitions[100];
static int def_count = 0;

void register_token(char *name, AFN* afn) {
    definitions[def_count].name = name;
    definitions[def_count].afn = afn;
    def_count++;
}

int is_accepted(AFN *afn, const char *word, TokenType *type) {
    if (!afn) return 0;
    
    State *curr_states[1024];
    int curr_count = 1;
    curr_states[0] = afn->start;

    // Epsilon closure (simplified: no epsilon in our current regexes yet)
    // If we had epsilon, we'd need a real closure function here.

    for (int i = 0; word[i]; i++) {
        State *next_states[1024];
        int next_count = 0;

        for (int j = 0; j < curr_count; j++) {
            Transition *t = curr_states[j]->transitions;
            while (t) {
                if (t->chars) {
                    CharSet *cs = t->chars;
                    while (cs) {
                        if (word[i] >= cs->start && word[i] <= cs->end) {
                            next_states[next_count++] = t->to;
                            break;
                        }
                        cs = cs->next;
                    }
                }
                t = t->next;
            }
        }
        if (next_count == 0) return 0;
        curr_count = next_count;
        memcpy(curr_states, next_states, sizeof(State*) * next_count);
    }

    for (int i = 0; i < curr_count; i++) {
        if (curr_states[i]->is_final) {
            *type = curr_states[i]->token_type;
            return 1;
        }
    }
    return 0;
}

void init_lexer() {
    // Keywords
    register_token("PROCESS", build_string_afn("PROCESS", TOK_PROCESS));
    register_token("CONFIG", build_string_afn("CONFIG", TOK_CONFIG));
    register_token("PIPELINE", build_string_afn("PIPELINE", TOK_PIPELINE));
    register_token("integer", build_string_afn("integer", TOK_TYPE_INT));
    register_token("text", build_string_afn("text", TOK_TYPE_TEXT));
    register_token("probability", build_string_afn("probability", TOK_TYPE_PROB));
    register_token("verdict", build_string_afn("verdict", TOK_TYPE_VERDICT));
    register_token("dictionary", build_string_afn("dictionary", TOK_TYPE_DICT));
    register_token("batch", build_string_afn("batch", TOK_TYPE_BATCH));
    register_token("VALID", build_string_afn("VALID", TOK_VALID));
    register_token("SUSPECT", build_string_afn("SUSPECT", TOK_SUSPECT));
    register_token("REJECT", build_string_afn("REJECT", TOK_REJECT));
    register_token("INGEST", build_string_afn("INGEST", TOK_INGEST));
    register_token("FROM", build_string_afn("FROM", TOK_FROM));
    register_token("DISPATCH", build_string_afn("DISPATCH", TOK_DISPATCH));
    register_token("TO", build_string_afn("TO", TOK_TO));
    register_token("LOG", build_string_afn("LOG", TOK_LOG));
    register_token("LEVEL", build_string_afn("LEVEL", TOK_LEVEL));
    register_token("NORMALIZE", build_string_afn("NORMALIZE", TOK_NORMALIZE));
    register_token("MASK", build_string_afn("MASK", TOK_MASK));
    register_token("WITH", build_string_afn("WITH", TOK_WITH));
    register_token("SCAN", build_string_afn("SCAN", TOK_SCAN));
    register_token("WHILE", build_string_afn("WHILE", TOK_WHILE));
    register_token("IF", build_string_afn("IF", TOK_IF));
    register_token("ELSE", build_string_afn("ELSE", TOK_ELSE));
    register_token("NULL", build_string_afn("NULL", TOK_NULL));
    register_token("IN", build_string_afn("IN", TOK_IN));
    register_token("CONTAINS", build_string_afn("CONTAINS", TOK_CONTAINS));
    register_token("AND", build_string_afn("AND", TOK_AND));
    register_token("OR", build_string_afn("OR", TOK_OR));
    register_token("NOT", build_string_afn("NOT", TOK_NOT));

    // Operators
    register_token("ASSIGN", build_string_afn("=", TOK_ASSIGN));
    register_token("EQ", build_string_afn("==", TOK_EQ));
    register_token("NEQ", build_string_afn("!=", TOK_NEQ));
    register_token("LE", build_string_afn("<=", TOK_LE));
    register_token("GE", build_string_afn(">=", TOK_GE));
    register_token("LT", build_string_afn("<", TOK_LT));
    register_token("GT", build_string_afn(">", TOK_GT));
    register_token("PLUS", build_string_afn("+", TOK_PLUS));
    register_token("MINUS", build_string_afn("-", TOK_MINUS));
    register_token("MULT", build_string_afn("*", TOK_MULT));
    register_token("DIV", build_string_afn("/", TOK_DIV));
    register_token("MOD", build_string_afn("%", TOK_MOD));

    // Delimiters
    register_token("LBRACE", build_string_afn("{", TOK_LBRACE));
    register_token("RBRACE", build_string_afn("}", TOK_RBRACE));
    register_token("LPAREN", build_string_afn("(", TOK_LPAREN));
    register_token("RPAREN", build_string_afn(")", TOK_RPAREN));
    register_token("LBRACKET", build_string_afn("[", TOK_LBRACKET));
    register_token("RBRACKET", build_string_afn("]", TOK_RBRACKET));
    register_token("COMMA", build_string_afn(",", TOK_COMMA));

    // Regex-based literals (priority order: more specific first)
    register_token("FLOAT", build_regex_float_afn());
    register_token("INTEGER", build_regex_int_afn());
    register_token("ID", build_regex_id_afn());
    register_token("STRING", build_regex_string_afn());
}

TokenType scan_token(const char *word) {
    // We check all registrations. In a real DFA this would be faster, 
    // but here we simulate multiple NFAs.
    // Order matters: keywords should be checked before IDs.
    for (int i = 0; i < def_count; i++) {
        TokenType type;
        if (is_accepted(definitions[i].afn, word, &type)) {
            return type;
        }
    }
    return TOK_ERROR;
}
