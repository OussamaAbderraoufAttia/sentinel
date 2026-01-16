%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Compiler_Core/symbol_table.h"
#include "../Compiler_Core/quads.h"
#include "sentinel.tab.h"

extern YYSTYPE yylval;

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
    return 0;
}

%%

