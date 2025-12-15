%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sentinel.h"

YYSTYPE yylval;

FILE *yyin;

const char* getTokenName(int token);
%}

%option noyywrap
%option yylineno

DIGIT [0-9]
LETTER [a-zA-Z]
ID {LETTER}({LETTER}|{DIGIT}|_)*
INTEGER {DIGIT}+
FLOAT {DIGIT}+\.{DIGIT}+
STRING \"([^\"\\]|\\.)*\"

%%

"//".* { }

[ \t\r]+ { }
\n { }

"PROCESS" { return TOK_PROCESS; }
"CONFIG" { return TOK_CONFIG; }
"PIPELINE" { return TOK_PIPELINE; }

"integer" { return TOK_TYPE_INT; }
"text" { return TOK_TYPE_TEXT; }
"probability" { return TOK_TYPE_PROB; }
"verdict" { return TOK_TYPE_VERDICT; }
"dictionary" { return TOK_TYPE_DICT; }
"batch" { return TOK_TYPE_BATCH; }

"VALID" { return TOK_VALID; }
"SUSPECT" { return TOK_SUSPECT; }
"REJECT" { return TOK_REJECT; }

"INGEST" { return TOK_INGEST; }
"FROM" { return TOK_FROM; }
"DISPATCH" { return TOK_DISPATCH; }
"TO" { return TOK_TO; }
"LOG" { return TOK_LOG; }
"LEVEL" { return TOK_LEVEL; }
"NORMALIZE" { return TOK_NORMALIZE; }
"MASK" { return TOK_MASK; }
"WITH" { return TOK_WITH; }
"SCAN" { return TOK_SCAN; }
"WHILE" { return TOK_WHILE; }
"IF" { return TOK_IF; }
"ELSE" { return TOK_ELSE; }
"NULL" { return TOK_NULL; }

"IN" { return TOK_IN; }
"CONTAINS" { return TOK_CONTAINS; }
"AND" { return TOK_AND; }
"OR" { return TOK_OR; }
"NOT" { return TOK_NOT; }

"==" { return TOK_EQ; }
"!=" { return TOK_NEQ; }
"<=" { return TOK_LE; }
">=" { return TOK_GE; }
"+" { return TOK_PLUS; }
"-" { return TOK_MINUS; }
"*" { return TOK_MULT; }
"/" { return TOK_DIV; }
"%" { return TOK_MOD; }
"=" { return TOK_ASSIGN; }
"<" { return TOK_LT; }
">" { return TOK_GT; }

"{" { return TOK_LBRACE; }
"}" { return TOK_RBRACE; }
"(" { return TOK_LPAREN; }
")" { return TOK_RPAREN; }
"[" { return TOK_LBRACKET; }
"]" { return TOK_RBRACKET; }
"," { return TOK_COMMA; }

{FLOAT} {
    yylval.fval = atof(yytext);
    return TOK_FLOAT_LIT;
}

{INTEGER} {
    yylval.ival = atoi(yytext);
    return TOK_INT_LIT;
}

{STRING} {
    yylval.sval = strdup(yytext);
    return TOK_STRING_LIT;
}

{ID} {
    yylval.sval = strdup(yytext);
    return TOK_ID;
}

. {
    printf("LEXICAL ERROR: '%s' at line %d\n", yytext, yylineno);
    return TOK_ERROR;
}

%%

const char* getTokenName(int token) {
    switch(token) {
        case TOK_PROCESS: return "TOK_PROCESS";
        case TOK_CONFIG: return "TOK_CONFIG";
        case TOK_PIPELINE: return "TOK_PIPELINE";

        case TOK_TYPE_INT: return "TOK_TYPE_INT";
        case TOK_TYPE_TEXT: return "TOK_TYPE_TEXT";
        case TOK_TYPE_PROB: return "TOK_TYPE_PROB";
        case TOK_TYPE_VERDICT: return "TOK_TYPE_VERDICT";
        case TOK_TYPE_DICT: return "TOK_TYPE_DICT";
        case TOK_TYPE_BATCH: return "TOK_TYPE_BATCH";

        case TOK_VALID: return "TOK_VALID";
        case TOK_SUSPECT: return "TOK_SUSPECT";
        case TOK_REJECT: return "TOK_REJECT";

        case TOK_INGEST: return "TOK_INGEST";
        case TOK_FROM: return "TOK_FROM";
        case TOK_DISPATCH: return "TOK_DISPATCH";
        case TOK_TO: return "TOK_TO";
        case TOK_LOG: return "TOK_LOG";
        case TOK_LEVEL: return "TOK_LEVEL";
        case TOK_NORMALIZE: return "TOK_NORMALIZE";
        case TOK_MASK: return "TOK_MASK";
        case TOK_WITH: return "TOK_WITH";
        case TOK_SCAN: return "TOK_SCAN";
        case TOK_WHILE: return "TOK_WHILE";
        case TOK_IF: return "TOK_IF";
        case TOK_ELSE: return "TOK_ELSE";
        case TOK_NULL: return "TOK_NULL";

        case TOK_IN: return "TOK_IN";
        case TOK_CONTAINS: return "TOK_CONTAINS";
        case TOK_AND: return "TOK_AND";
        case TOK_OR: return "TOK_OR";
        case TOK_NOT: return "TOK_NOT";

        case TOK_EQ: return "TOK_EQ";
        case TOK_NEQ: return "TOK_NEQ";
        case TOK_LE: return "TOK_LE";
        case TOK_GE: return "TOK_GE";
        case TOK_LT: return "TOK_LT";
        case TOK_GT: return "TOK_GT";

        case TOK_PLUS: return "TOK_PLUS";
        case TOK_MINUS: return "TOK_MINUS";
        case TOK_MULT: return "TOK_MULT";
        case TOK_DIV: return "TOK_DIV";
        case TOK_MOD: return "TOK_MOD";
        case TOK_ASSIGN: return "TOK_ASSIGN";

        case TOK_LBRACE: return "TOK_LBRACE";
        case TOK_RBRACE: return "TOK_RBRACE";
        case TOK_LPAREN: return "TOK_LPAREN";
        case TOK_RPAREN: return "TOK_RPAREN";
        case TOK_LBRACKET: return "TOK_LBRACKET";
        case TOK_RBRACKET: return "TOK_RBRACKET";
        case TOK_COMMA: return "TOK_COMMA";

        case TOK_INT_LIT: return "TOK_INT_LIT";
        case TOK_FLOAT_LIT: return "TOK_FLOAT_LIT";
        case TOK_STRING_LIT: return "TOK_STRING_LIT";
        case TOK_ID: return "TOK_ID";

        case TOK_ERROR: return "TOK_ERROR";
        default: return "UNKNOWN_TOKEN";
    }
}

int main(int argc, char **argv) {
    printf("=== SENTINEL LEXICAL ANALYZER TEST ===\n");

    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror("File open error");
            return 1;
        }
        printf("Reading file: %s\n", argv[1]);
    } else {
        printf("Reading from standard input (Ctrl+Z then Enter)...\n");
    }

    int token;
    while ((token = yylex()) != 0) {
        if (token == TOK_ERROR) continue;
        printf("Line %d : [%s] -> %s\n", yylineno, yytext, getTokenName(token));
    }

    printf("=== END OF TEST ===\n");
    return 0;
}
