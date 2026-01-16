#ifndef MANUAL_SYMBOLS_H
#define MANUAL_SYMBOLS_H

#include "../analyse_lexicale/lexer_common.h"

typedef struct ManualSymbol {
    char name[128];
    DataType type;
    int is_global;
    struct ManualSymbol *next;
} ManualSymbol;

typedef struct {
    ManualSymbol *head;
} ManualSymbolTable;

ManualSymbolTable* create_manual_table();
void insert_manual_symbol(ManualSymbolTable *list, char *name, DataType type, int is_global);
ManualSymbol* lookup_manual_symbol(ManualSymbolTable *config, ManualSymbolTable *pipeline, char *name);

#endif
