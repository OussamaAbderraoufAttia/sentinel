/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_SENTINEL_TAB_H_INCLUDED
# define YY_YY_SENTINEL_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOK_PROCESS = 258,
     TOK_CONFIG = 259,
     TOK_PIPELINE = 260,
     TOK_TYPE_INT = 261,
     TOK_TYPE_TEXT = 262,
     TOK_TYPE_PROB = 263,
     TOK_TYPE_VERDICT = 264,
     TOK_TYPE_DICT = 265,
     TOK_TYPE_BATCH = 266,
     TOK_INT_LIT = 267,
     TOK_FLOAT_LIT = 268,
     TOK_STRING_LIT = 269,
     TOK_ID = 270,
     TOK_VALID = 271,
     TOK_SUSPECT = 272,
     TOK_REJECT = 273,
     TOK_INGEST = 274,
     TOK_FROM = 275,
     TOK_DISPATCH = 276,
     TOK_TO = 277,
     TOK_LOG = 278,
     TOK_LEVEL = 279,
     TOK_NORMALIZE = 280,
     TOK_MASK = 281,
     TOK_WITH = 282,
     TOK_SCAN = 283,
     TOK_WHILE = 284,
     TOK_IF = 285,
     TOK_ELSE = 286,
     TOK_NULL = 287,
     TOK_IN = 288,
     TOK_CONTAINS = 289,
     TOK_AND = 290,
     TOK_OR = 291,
     TOK_NOT = 292,
     TOK_EQ = 293,
     TOK_NEQ = 294,
     TOK_LE = 295,
     TOK_GE = 296,
     TOK_LT = 297,
     TOK_GT = 298,
     TOK_PLUS = 299,
     TOK_MINUS = 300,
     TOK_MULT = 301,
     TOK_DIV = 302,
     TOK_MOD = 303,
     TOK_ASSIGN = 304,
     TOK_LBRACE = 305,
     TOK_RBRACE = 306,
     TOK_LPAREN = 307,
     TOK_RPAREN = 308,
     TOK_LBRACKET = 309,
     TOK_RBRACKET = 310,
     TOK_COMMA = 311
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 21 "sentinel.y"

    int ival;
    float fval;
    char *sval;
    struct {
        char *name;
        DataType type;
    } expr;


/* Line 2058 of yacc.c  */
#line 124 "sentinel.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_SENTINEL_TAB_H_INCLUDED  */
