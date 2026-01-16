#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    TYPE_INT,
    TYPE_TEXT,
    TYPE_PROB,
    TYPE_VERDICT,
    TYPE_DICT,
    TYPE_BATCH,
    TYPE_NONE
} DataType;

typedef struct Symbol {
    char *name;
    DataType type;
    int is_global; // 1 for CONFIG, 0 for PIPELINE
    struct Symbol *next;
} Symbol;

typedef struct SymbolTable {
    Symbol *head;
} SymbolTable;

SymbolTable* create_table();
Symbol* insert_symbol(SymbolTable *table, char *name, DataType type, int is_global);
Symbol* lookup_symbol(SymbolTable *config_table, SymbolTable *pipeline_table, char *name);
void print_table(SymbolTable *table, const char *label);
const char* type_to_string(DataType type);

#endif
