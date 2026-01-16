#ifndef LEXER_COMMON_H
#define LEXER_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    TYPE_INT,
    TYPE_TEXT,
    TYPE_PROB,
    TYPE_VERDICT,
    TYPE_DICT,
    TYPE_BATCH
} DataType;

// SENTINEL Token Types
typedef enum {
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
    TOK_LBRACE, TOK_RBRACE, TOK_LPAREN, TOK_RPAREN, TOK_LBRACKET, TOK_RBRACKET, TOK_COMMA,

    TOK_EOF, TOK_ERROR
} TokenType;

typedef struct CharSet {
    char start;
    char end;
    struct CharSet *next;
} CharSet;

struct State;

typedef struct Transition {
    CharSet *chars; // NULL for epsilon
    struct State *to;
    struct Transition *next;
} Transition;

typedef struct State {
    int id;
    Transition *transitions;
    int is_final;
    TokenType token_type; // For final states
} State;

typedef struct AFN {
    State *start;
    State *end;
} AFN;

// Function declarations
State* create_state(int is_final, TokenType type);
CharSet* create_charset(char start, char end);
void add_transition(State *from, State *to, CharSet *cs);
AFN* build_string_afn(const char *str, TokenType type);
AFN* build_regex_id_afn();
AFN* build_regex_int_afn();
AFN* build_regex_float_afn();
AFN* build_regex_string_afn();

// Lexer control
void init_lexer();
TokenType scan_token(const char *word);

#endif
