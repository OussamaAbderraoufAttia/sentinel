#ifndef PARSER_H
#define PARSER_H

#include "../analyse_lexicale/lexer_common.h"

typedef struct {
    TokenType type;
    char lexeme[1024];
    int line;
} Token;

void parse_program();
void init_parser(FILE *f);

#endif
