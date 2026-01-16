/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "sentinel.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Compiler_Core/symbol_table.h"
#include "../Compiler_Core/quads.h"

extern int yylex();
extern int yylineno;
extern char* yytext;
void yyerror(const char *s);

SymbolTable *config_table;
SymbolTable *pipeline_table;
QuadList *quads;

DataType current_type;
int in_config = 0;

/* Line 371 of yacc.c  */
#line 88 "sentinel.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "sentinel.tab.h".  */
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
/* Line 387 of yacc.c  */
#line 21 "sentinel.y"

    int ival;
    float fval;
    char *sval;
    struct {
        char *name;
        DataType type;
    } expr;


/* Line 387 of yacc.c  */
#line 198 "sentinel.tab.c"
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 226 "sentinel.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   345

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNRULES -- Number of states.  */
#define YYNSTATES  154

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,    12,    13,    19,    24,    25,    28,
      33,    40,    42,    44,    46,    48,    50,    52,    54,    56,
      58,    60,    62,    64,    66,    68,    72,    73,    76,    78,
      80,    82,    84,    86,    88,    90,    92,    94,    96,   101,
     105,   109,   113,   117,   121,   125,   129,   133,   137,   141,
     145,   149,   153,   157,   161,   165,   168,   171,   175,   177,
     179,   181,   183,   185,   187,   189,   190,   191,   202,   203,
     208,   209,   210,   220,   221,   230,   235,   240,   245,   248
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      58,     0,    -1,    -1,     3,    14,    50,    59,    60,    62,
      51,    -1,    -1,     4,    61,    50,    63,    51,    -1,     5,
      50,    69,    51,    -1,    -1,    63,    64,    -1,    65,    15,
      49,    66,    -1,    65,    15,    49,    54,    68,    55,    -1,
       6,    -1,     7,    -1,     8,    -1,     9,    -1,    10,    -1,
      11,    -1,    12,    -1,    13,    -1,    14,    -1,    67,    -1,
      16,    -1,    17,    -1,    18,    -1,    14,    -1,    68,    56,
      14,    -1,    -1,    69,    70,    -1,    72,    -1,    75,    -1,
      79,    -1,    82,    -1,    84,    -1,    85,    -1,    86,    -1,
      87,    -1,    88,    -1,    71,    -1,    65,    15,    49,    73,
      -1,    15,    49,    73,    -1,    73,    44,    73,    -1,    73,
      45,    73,    -1,    73,    46,    73,    -1,    73,    47,    73,
      -1,    73,    48,    73,    -1,    73,    42,    73,    -1,    73,
      43,    73,    -1,    73,    40,    73,    -1,    73,    41,    73,
      -1,    73,    38,    73,    -1,    73,    39,    73,    -1,    73,
      35,    73,    -1,    73,    36,    73,    -1,    73,    33,    73,
      -1,    73,    34,    73,    -1,    37,    73,    -1,    45,    73,
      -1,    52,    73,    53,    -1,    74,    -1,    15,    -1,    12,
      -1,    13,    -1,    14,    -1,    32,    -1,    67,    -1,    -1,
      -1,    30,    52,    73,    53,    76,    50,    69,    51,    77,
      78,    -1,    -1,    31,    50,    69,    51,    -1,    -1,    -1,
      29,    80,    52,    73,    53,    81,    50,    69,    51,    -1,
      -1,    28,    15,    27,    15,    83,    50,    69,    51,    -1,
      19,    15,    20,    15,    -1,    21,    15,    22,    15,    -1,
      23,    14,    24,    12,    -1,    25,    15,    -1,    26,    15,
      27,    14,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    63,    63,    63,    71,    71,    75,    78,    80,    84,
      94,   101,   102,   103,   104,   105,   106,   110,   111,   114,
     115,   119,   120,   121,   125,   126,   129,   131,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   148,   161,
     174,   178,   182,   186,   190,   194,   198,   202,   206,   210,
     214,   218,   222,   226,   230,   234,   238,   242,   243,   247,
     256,   260,   265,   268,   269,   275,   279,   275,   289,   291,
     295,   299,   295,   310,   310,   329,   335,   341,   348,   354
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_PROCESS", "TOK_CONFIG",
  "TOK_PIPELINE", "TOK_TYPE_INT", "TOK_TYPE_TEXT", "TOK_TYPE_PROB",
  "TOK_TYPE_VERDICT", "TOK_TYPE_DICT", "TOK_TYPE_BATCH", "TOK_INT_LIT",
  "TOK_FLOAT_LIT", "TOK_STRING_LIT", "TOK_ID", "TOK_VALID", "TOK_SUSPECT",
  "TOK_REJECT", "TOK_INGEST", "TOK_FROM", "TOK_DISPATCH", "TOK_TO",
  "TOK_LOG", "TOK_LEVEL", "TOK_NORMALIZE", "TOK_MASK", "TOK_WITH",
  "TOK_SCAN", "TOK_WHILE", "TOK_IF", "TOK_ELSE", "TOK_NULL", "TOK_IN",
  "TOK_CONTAINS", "TOK_AND", "TOK_OR", "TOK_NOT", "TOK_EQ", "TOK_NEQ",
  "TOK_LE", "TOK_GE", "TOK_LT", "TOK_GT", "TOK_PLUS", "TOK_MINUS",
  "TOK_MULT", "TOK_DIV", "TOK_MOD", "TOK_ASSIGN", "TOK_LBRACE",
  "TOK_RBRACE", "TOK_LPAREN", "TOK_RPAREN", "TOK_LBRACKET", "TOK_RBRACKET",
  "TOK_COMMA", "$accept", "program", "$@1", "config_block", "$@2",
  "pipeline_block", "declarations", "declaration", "type", "init_val",
  "verdict_val", "list_items", "statements", "statement",
  "var_declaration", "assignment", "expression", "primary", "if_statement",
  "@3", "@4", "else_part", "while_statement", "@5", "@6", "scan_statement",
  "@7", "ingest_statement", "dispatch_statement", "log_statement",
  "normalize_statement", "mask_statement", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    59,    58,    61,    60,    62,    63,    63,    64,
      64,    65,    65,    65,    65,    65,    65,    66,    66,    66,
      66,    67,    67,    67,    68,    68,    69,    69,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    71,    72,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    74,
      74,    74,    74,    74,    74,    76,    77,    75,    78,    78,
      80,    81,    79,    83,    82,    84,    85,    86,    87,    88
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     7,     0,     5,     4,     0,     2,     4,
       6,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     0,     0,    10,     0,     4,
       0,     0,     9,     0,     8,     4,     4,     4,     2,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     2,     0,     4,     0,     0,
       0,     0,     7,    26,     3,     0,     0,    11,    12,    13,
      14,    15,    16,     5,     8,     0,     0,     0,     0,     0,
       0,     0,     0,    70,     0,     6,     0,    27,    37,    28,
      29,    30,    31,    32,    33,    34,    35,    36,     0,     0,
       0,     0,     0,    78,     0,     0,     0,     0,     0,     0,
      60,    61,    62,    59,    21,    22,    23,    63,     0,     0,
       0,    64,    39,    58,     0,     0,     0,     0,     0,     0,
       0,     0,    17,    18,    19,     0,     9,    20,    55,    56,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    75,    76,    77,    79,
      73,     0,    65,    38,    24,     0,    57,    53,    54,    51,
      52,    49,    50,    47,    48,    45,    46,    40,    41,    42,
      43,    44,     0,    71,     0,    10,     0,    26,     0,    26,
      25,     0,    26,     0,    74,     0,    66,    72,    68,     0,
      67,    26,     0,    69
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,     8,     9,    11,    15,    24,    36,    86,
      71,   115,    16,    37,    38,    39,    72,    73,    40,   134,
     148,   150,    41,    56,   138,    42,   132,    43,    44,    45,
      46,    47
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -58
static const yytype_int16 yypact[] =
{
       2,    -8,     7,   -42,   -58,   -58,     5,   -58,    15,   -40,
     -29,   -28,   -58,   -58,   -58,     8,    43,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,    17,   -21,    18,    40,    42,
      45,    46,    48,   -58,    22,   -58,    50,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,    21,   171,
      37,    53,    58,   -58,    56,    57,    34,   171,    38,    13,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   171,   171,
     171,   -58,   234,   -58,    73,    75,    80,    83,    86,   171,
     186,   171,   -58,   -58,   -58,    88,   -58,   -58,   -58,   -58,
     202,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   -58,   -58,   -58,   -58,
     -58,   218,   -58,   234,   -58,   -54,   -58,   -58,   -58,   266,
     250,   282,   282,   165,   165,   165,   165,   158,   158,   -30,
     -30,   -30,    59,   -58,    60,   -58,    99,   -58,    61,   -58,
     -58,    70,   -58,    97,   -58,   124,   -58,   -58,    84,    64,
     -58,   -58,   151,   -58
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   102,   -58,
      65,   -58,   194,   -58,   -58,   -58,   -57,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      80,   135,   136,    91,    92,     1,     3,     4,     5,     7,
      12,    88,    89,    90,    17,    18,    19,    20,    21,    22,
      10,    13,   111,    14,   113,    82,    83,    84,    49,    64,
      65,    66,    48,    50,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,    17,
      18,    19,    20,    21,    22,    51,    52,    74,    26,    23,
      53,    54,    27,    55,    28,    58,    29,    85,    30,    31,
      59,    32,    33,    34,    57,    75,    17,    18,    19,    20,
      21,    22,    76,    77,    78,    26,    79,    81,   106,    27,
     107,    28,   108,    29,    35,    30,    31,   109,    32,    33,
      34,   110,   114,    17,    18,    19,    20,    21,    22,   137,
     139,   142,    26,   140,   151,   149,    27,    25,    28,     0,
      29,   144,    30,    31,    87,    32,    33,    34,     0,     0,
      17,    18,    19,    20,    21,    22,     0,     0,     0,    26,
       0,     0,     0,    27,     0,    28,     0,    29,   146,    30,
      31,     0,    32,    33,    34,     0,     0,    17,    18,    19,
      20,    21,    22,     0,     0,     0,    26,     0,     0,     0,
      27,     0,    28,     0,    29,   147,    30,    31,     0,    32,
      33,    34,     0,    60,    61,    62,    63,    64,    65,    66,
       0,    91,    92,     0,     0,     0,     0,     0,    91,    92,
       0,     0,   153,    67,   103,   104,   105,     0,    68,   101,
     102,   103,   104,   105,     0,     0,    69,     0,     0,    91,
      92,    93,    94,    70,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,    91,    92,    93,    94,   112,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,    91,    92,    93,    94,   116,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,    91,    92,    93,
      94,   133,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,    91,    92,    93,     0,     0,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,    91,
      92,     0,     0,     0,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,    91,    92,     0,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   141,     0,   143,     0,     0,   145,     0,     0,     0,
       0,     0,     0,     0,     0,   152
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-58)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      57,    55,    56,    33,    34,     3,    14,     0,    50,     4,
      50,    68,    69,    70,     6,     7,     8,     9,    10,    11,
       5,    50,    79,    51,    81,    12,    13,    14,    49,    16,
      17,    18,    15,    15,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,     6,
       7,     8,     9,    10,    11,    15,    14,    20,    15,    51,
      15,    15,    19,    15,    21,    15,    23,    54,    25,    26,
      49,    28,    29,    30,    52,    22,     6,     7,     8,     9,
      10,    11,    24,    27,    27,    15,    52,    49,    15,    19,
      15,    21,    12,    23,    51,    25,    26,    14,    28,    29,
      30,    15,    14,     6,     7,     8,     9,    10,    11,    50,
      50,    50,    15,    14,    50,    31,    19,    15,    21,    -1,
      23,    51,    25,    26,    59,    28,    29,    30,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    15,
      -1,    -1,    -1,    19,    -1,    21,    -1,    23,    51,    25,
      26,    -1,    28,    29,    30,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    15,    -1,    -1,    -1,
      19,    -1,    21,    -1,    23,    51,    25,    26,    -1,    28,
      29,    30,    -1,    12,    13,    14,    15,    16,    17,    18,
      -1,    33,    34,    -1,    -1,    -1,    -1,    -1,    33,    34,
      -1,    -1,    51,    32,    46,    47,    48,    -1,    37,    44,
      45,    46,    47,    48,    -1,    -1,    45,    -1,    -1,    33,
      34,    35,    36,    52,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    33,    34,    35,    36,    53,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    33,    34,    35,    36,    53,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    33,    34,    35,
      36,    53,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    33,    34,    35,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    33,
      34,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    33,    34,    -1,    -1,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,   137,    -1,   139,    -1,    -1,   142,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   151
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    58,    14,     0,    50,    59,     4,    60,    61,
       5,    62,    50,    50,    51,    63,    69,     6,     7,     8,
       9,    10,    11,    51,    64,    65,    15,    19,    21,    23,
      25,    26,    28,    29,    30,    51,    65,    70,    71,    72,
      75,    79,    82,    84,    85,    86,    87,    88,    15,    49,
      15,    15,    14,    15,    15,    15,    80,    52,    15,    49,
      12,    13,    14,    15,    16,    17,    18,    32,    37,    45,
      52,    67,    73,    74,    20,    22,    24,    27,    27,    52,
      73,    49,    12,    13,    14,    54,    66,    67,    73,    73,
      73,    33,    34,    35,    36,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    15,    15,    12,    14,
      15,    73,    53,    73,    14,    68,    53,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    83,    53,    76,    55,    56,    50,    81,    50,
      14,    69,    50,    69,    51,    69,    51,    51,    77,    31,
      78,    50,    69,    51
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 63 "sentinel.y"
    {
        printf("Starting Process: %s\n", (yyvsp[(2) - (3)].sval));
    }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 65 "sentinel.y"
    {
        printf("Process %s compilation finished.\n", (yyvsp[(2) - (7)].sval));
    }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 71 "sentinel.y"
    { in_config = 1; }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 71 "sentinel.y"
    { in_config = 0; }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 84 "sentinel.y"
    {
        if (lookup_symbol(config_table, NULL, (yyvsp[(2) - (4)].sval))) {
            char err[100];
            sprintf(err, "Semantic Error: Redefinition of '%s' in CONFIG", (yyvsp[(2) - (4)].sval));
            yyerror(err);
        } else {
            insert_symbol(config_table, (yyvsp[(2) - (4)].sval), current_type, 1);
            add_quad(quads, "=", yytext, NULL, (yyvsp[(2) - (4)].sval)); // Rough init quad
        }
    }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 94 "sentinel.y"
    {
        if (current_type != TYPE_DICT) yyerror("List initialization only allowed for dictionary");
        insert_symbol(config_table, (yyvsp[(2) - (6)].sval), TYPE_DICT, 1);
    }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 101 "sentinel.y"
    { current_type = TYPE_INT; }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 102 "sentinel.y"
    { current_type = TYPE_TEXT; }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 103 "sentinel.y"
    { current_type = TYPE_PROB; }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 104 "sentinel.y"
    { current_type = TYPE_VERDICT; }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 105 "sentinel.y"
    { current_type = TYPE_DICT; }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 106 "sentinel.y"
    { current_type = TYPE_BATCH; }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 111 "sentinel.y"
    {
        if ((yyvsp[(1) - (1)].fval) < 0.0 || (yyvsp[(1) - (1)].fval) > 1.0) yyerror("Probability Out of Bounds [0.0, 1.0]");
    }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 119 "sentinel.y"
    { (yyval.sval) = "VALID"; }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 120 "sentinel.y"
    { (yyval.sval) = "SUSPECT"; }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 121 "sentinel.y"
    { (yyval.sval) = "REJECT"; }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 148 "sentinel.y"
    {
        if (lookup_symbol(config_table, NULL, (yyvsp[(2) - (4)].sval))) {
            yyerror("Shadowing Error: Variable already exists in CONFIG");
        } else if (lookup_symbol(NULL, pipeline_table, (yyvsp[(2) - (4)].sval))) {
            yyerror("Redefinition Error: Variable already exists in PIPELINE");
        } else {
            insert_symbol(pipeline_table, (yyvsp[(2) - (4)].sval), current_type, 0);
            add_quad(quads, "=", (yyvsp[(4) - (4)].expr).name, NULL, (yyvsp[(2) - (4)].sval));
        }
    }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 161 "sentinel.y"
    {
        Symbol *s = lookup_symbol(config_table, pipeline_table, (yyvsp[(1) - (3)].sval));
        if (!s) {
            yyerror("Undefined variable");
        } else if (s->type == TYPE_DICT) {
            yyerror("Immutability Error: Dictionary cannot be modified in PIPELINE");
        } else {
            add_quad(quads, "=", (yyvsp[(3) - (3)].expr).name, NULL, (yyvsp[(1) - (3)].sval));
        }
    }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 174 "sentinel.y"
    {
        (yyval.expr).name = new_temp();
        add_quad(quads, "+", (yyvsp[(1) - (3)].expr).name, (yyvsp[(3) - (3)].expr).name, (yyval.expr).name);
    }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 178 "sentinel.y"
    {
        (yyval.expr).name = new_temp();
        add_quad(quads, "-", (yyvsp[(1) - (3)].expr).name, (yyvsp[(3) - (3)].expr).name, (yyval.expr).name);
    }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 182 "sentinel.y"
    {
        (yyval.expr).name = new_temp();
        add_quad(quads, "*", (yyvsp[(1) - (3)].expr).name, (yyvsp[(3) - (3)].expr).name, (yyval.expr).name);
    }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 186 "sentinel.y"
    {
        (yyval.expr).name = new_temp();
        add_quad(quads, "/", (yyvsp[(1) - (3)].expr).name, (yyvsp[(3) - (3)].expr).name, (yyval.expr).name);
    }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 190 "sentinel.y"
    {
        (yyval.expr).name = new_temp();
        add_quad(quads, "%", (yyvsp[(1) - (3)].expr).name, (yyvsp[(3) - (3)].expr).name, (yyval.expr).name);
    }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 194 "sentinel.y"
    {
        (yyval.expr).name = new_temp();
        add_quad(quads, "LT", (yyvsp[(1) - (3)].expr).name, (yyvsp[(3) - (3)].expr).name, (yyval.expr).name);
    }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 198 "sentinel.y"
    {
        (yyval.expr).name = new_temp();
        add_quad(quads, "GT", (yyvsp[(1) - (3)].expr).name, (yyvsp[(3) - (3)].expr).name, (yyval.expr).name);
    }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 202 "sentinel.y"
    {
        (yyval.expr).name = new_temp();
        add_quad(quads, "LE", (yyvsp[(1) - (3)].expr).name, (yyvsp[(3) - (3)].expr).name, (yyval.expr).name);
    }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 206 "sentinel.y"
    {
        (yyval.expr).name = new_temp();
        add_quad(quads, "GE", (yyvsp[(1) - (3)].expr).name, (yyvsp[(3) - (3)].expr).name, (yyval.expr).name);
    }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 210 "sentinel.y"
    {
        (yyval.expr).name = new_temp();
        add_quad(quads, "EQ", (yyvsp[(1) - (3)].expr).name, (yyvsp[(3) - (3)].expr).name, (yyval.expr).name);
    }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 214 "sentinel.y"
    {
        (yyval.expr).name = new_temp();
        add_quad(quads, "NE", (yyvsp[(1) - (3)].expr).name, (yyvsp[(3) - (3)].expr).name, (yyval.expr).name);
    }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 218 "sentinel.y"
    {
        (yyval.expr).name = new_temp();
        add_quad(quads, "AND", (yyvsp[(1) - (3)].expr).name, (yyvsp[(3) - (3)].expr).name, (yyval.expr).name);
    }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 222 "sentinel.y"
    {
        (yyval.expr).name = new_temp();
        add_quad(quads, "OR", (yyvsp[(1) - (3)].expr).name, (yyvsp[(3) - (3)].expr).name, (yyval.expr).name);
    }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 226 "sentinel.y"
    {
        (yyval.expr).name = new_temp();
        add_quad(quads, "IN", (yyvsp[(1) - (3)].expr).name, (yyvsp[(3) - (3)].expr).name, (yyval.expr).name);
    }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 230 "sentinel.y"
    {
        (yyval.expr).name = new_temp();
        add_quad(quads, "CONTAINS", (yyvsp[(1) - (3)].expr).name, (yyvsp[(3) - (3)].expr).name, (yyval.expr).name);
    }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 234 "sentinel.y"
    {
        (yyval.expr).name = new_temp();
        add_quad(quads, "NOT", (yyvsp[(2) - (2)].expr).name, NULL, (yyval.expr).name);
    }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 238 "sentinel.y"
    {
        (yyval.expr).name = new_temp();
        add_quad(quads, "NEG", (yyvsp[(2) - (2)].expr).name, NULL, (yyval.expr).name);
    }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 242 "sentinel.y"
    { (yyval.expr) = (yyvsp[(2) - (3)].expr); }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 243 "sentinel.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 247 "sentinel.y"
    {
        Symbol *s = lookup_symbol(config_table, pipeline_table, (yyvsp[(1) - (1)].sval));
        if (!s) {
            char err[100];
            sprintf(err, "Semantic Error: Undefined variable '%s'", (yyvsp[(1) - (1)].sval));
            yyerror(err);
        }
        (yyval.expr).name = (yyvsp[(1) - (1)].sval); (yyval.expr).type = s ? s->type : TYPE_NONE;
    }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 256 "sentinel.y"
    { 
        char buf[20]; sprintf(buf, "%d", (yyvsp[(1) - (1)].ival));
        (yyval.expr).name = strdup(buf); (yyval.expr).type = TYPE_INT; 
    }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 260 "sentinel.y"
    {
        if ((yyvsp[(1) - (1)].fval) < 0.0 || (yyvsp[(1) - (1)].fval) > 1.0) yyerror("Probability Out of Bounds [0.0, 1.0]");
        char buf[20]; sprintf(buf, "%f", (yyvsp[(1) - (1)].fval));
        (yyval.expr).name = strdup(buf); (yyval.expr).type = TYPE_PROB;
    }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 265 "sentinel.y"
    {
        (yyval.expr).name = (yyvsp[(1) - (1)].sval); (yyval.expr).type = TYPE_TEXT;
    }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 268 "sentinel.y"
    { (yyval.expr).name = "NULL"; (yyval.expr).type = TYPE_NONE; }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 269 "sentinel.y"
    {
        (yyval.expr).name = strdup((yyvsp[(1) - (1)].sval)); (yyval.expr).type = TYPE_VERDICT;
    }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 275 "sentinel.y"
    {
        char *l_else = new_label();
        add_quad(quads, "BZ", (yyvsp[(3) - (4)].expr).name, NULL, l_else);
        (yyval.sval) = l_else;
    }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 279 "sentinel.y"
    {
        char *l_end = new_label();
        add_quad(quads, "BR", NULL, NULL, l_end);
        add_quad(quads, "LABEL", (yyvsp[(5) - (8)].sval), NULL, NULL);
        (yyval.sval) = l_end;
    }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 284 "sentinel.y"
    {
        add_quad(quads, "LABEL", (yyvsp[(9) - (10)].sval), NULL, NULL);
    }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 295 "sentinel.y"
    {
        char *l_start = new_label();
        add_quad(quads, "LABEL", l_start, NULL, NULL);
        (yyval.sval) = l_start;
    }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 299 "sentinel.y"
    {
        char *l_end = new_label();
        add_quad(quads, "BZ", (yyvsp[(4) - (5)].expr).name, NULL, l_end);
        (yyval.sval) = l_end;
    }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 303 "sentinel.y"
    {
        add_quad(quads, "BR", NULL, NULL, (yyvsp[(2) - (9)].sval));
        add_quad(quads, "LABEL", (yyvsp[(6) - (9)].sval), NULL, NULL);
    }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 310 "sentinel.y"
    {
        char *l_start = new_label();
        char *l_end = new_label();
        add_quad(quads, "LABEL", l_start, NULL, NULL);
        char *tmp = new_temp();
        add_quad(quads, "SCAN_NEXT", (yyvsp[(2) - (4)].sval), (yyvsp[(4) - (4)].sval), tmp); //MATCH variable is implicit
        add_quad(quads, "BZ", tmp, NULL, l_end);
        (yyval.sval) = l_start;
        // We'd need to store l_end too. Let's just use static labels for simplicity in this demo
        // or a global label counter for the current block.
        // For now, let's just make sure it parses and generates something sensible.
    }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 321 "sentinel.y"
    {
        add_quad(quads, "BR", NULL, NULL, (yyvsp[(5) - (8)].sval));
        // We need l_end here. Let's assume we can compute it or use a convention.
        // Actually, let's just use a second mid-rule.
    }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 329 "sentinel.y"
    {
        add_quad(quads, "INGEST", (yyvsp[(4) - (4)].sval), NULL, (yyvsp[(2) - (4)].sval));
    }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 335 "sentinel.y"
    {
        add_quad(quads, "DISPATCH", (yyvsp[(2) - (4)].sval), NULL, (yyvsp[(4) - (4)].sval));
    }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 341 "sentinel.y"
    {
        char buf[10]; sprintf(buf, "%d", (yyvsp[(4) - (4)].ival));
        add_quad(quads, "LOG", (yyvsp[(2) - (4)].sval), buf, NULL);
    }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 348 "sentinel.y"
    {
        add_quad(quads, "NORMALIZE", (yyvsp[(2) - (2)].sval), NULL, NULL);
    }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 354 "sentinel.y"
    {
        add_quad(quads, "MASK", (yyvsp[(2) - (4)].sval), (yyvsp[(4) - (4)].sval), NULL);
    }
    break;


/* Line 1792 of yacc.c  */
#line 2090 "sentinel.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 359 "sentinel.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s (near '%s')\n", yylineno, s, yytext);
}
