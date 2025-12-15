/* sentinel.h */
#ifndef SENTINEL_H
#define SENTINEL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definition of Token Types */
typedef enum {
    /* End of File */
    TOK_EOF = 0,

    /* Structural Keywords */
    TOK_PROCESS = 258,
    TOK_CONFIG,
    TOK_PIPELINE,

    /* Data Types (Lowercase in PDF) */
    TOK_TYPE_INT,       // integer
    TOK_TYPE_TEXT,      // text
    TOK_TYPE_PROB,      // probability
    TOK_TYPE_VERDICT,   // verdict
    TOK_TYPE_DICT,      // dictionary
    TOK_TYPE_BATCH,     // batch

    /* Verdict Constants */
    TOK_VALID,
    TOK_SUSPECT,
    TOK_REJECT,

    /* Instructions */
    TOK_INGEST,
    TOK_FROM,
    TOK_DISPATCH,
    TOK_TO,
    TOK_LOG,
    TOK_LEVEL,
    TOK_NORMALIZE,
    TOK_MASK,
    TOK_WITH,
    TOK_SCAN,
    TOK_WHILE,
    TOK_IF,
    TOK_ELSE,
    TOK_NULL,

    /* Operators */
    TOK_PLUS,       // +
    TOK_MINUS,      // -
    TOK_MULT,       // *
    TOK_DIV,        // /
    TOK_MOD,        // %
    TOK_ASSIGN,     // =
    TOK_EQ,         // ==
    TOK_NEQ,        // !=
    TOK_LT,         // <
    TOK_GT,         // >
    TOK_LE,         // <=
    TOK_GE,         // >=
    
    /* Logical & Semantic Operators */
    TOK_AND,
    TOK_OR,
    TOK_NOT,
    TOK_IN,
    TOK_CONTAINS,

    /* Delimiters */
    TOK_LBRACE,     // {
    TOK_RBRACE,     // }
    TOK_LPAREN,     // (
    TOK_RPAREN,     // )
    TOK_LBRACKET,   // [
    TOK_RBRACKET,   // ]
    TOK_COMMA,      // ,

    /* Literals */
    TOK_ID,         // Identifiers
    TOK_INT_LIT,    // Integer numbers
    TOK_FLOAT_LIT,  // Probability/Float numbers
    TOK_STRING_LIT,  // "Text"

    /*Error Token*/
  TOK_ERROR = 9999

} TokenType;

/* Union to handle value passing (Simulating Bison's yylval) */
typedef union {
    int ival;
    float fval;
    char *sval;
} YYSTYPE;

extern YYSTYPE yylval;
extern int yylineno;

#endif