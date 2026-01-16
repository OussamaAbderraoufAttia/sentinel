#include "symbol_table.h"

SymbolTable* create_table() {
    SymbolTable *table = (SymbolTable*)malloc(sizeof(SymbolTable));
    table->head = NULL;
    return table;
}

Symbol* insert_symbol(SymbolTable *table, char *name, DataType type, int is_global) {
    Symbol *new_symbol = (Symbol*)malloc(sizeof(Symbol));
    new_symbol->name = strdup(name);
    new_symbol->type = type;
    new_symbol->is_global = is_global;
    new_symbol->next = table->head;
    table->head = new_symbol;
    return new_symbol;
}

Symbol* lookup_symbol(SymbolTable *config_table, SymbolTable *pipeline_table, char *name) {
    // Search in Local (Pipeline) first, then Global (Config)
    if (pipeline_table) {
        Symbol *curr = pipeline_table->head;
        while (curr) {
            if (strcmp(curr->name, name) == 0) return curr;
            curr = curr->next;
        }
    }
    if (config_table) {
        Symbol *curr = config_table->head;
        while (curr) {
            if (strcmp(curr->name, name) == 0) return curr;
            curr = curr->next;
        }
    }
    return NULL;
}

const char* type_to_string(DataType type) {
    switch (type) {
        case TYPE_INT: return "integer";
        case TYPE_TEXT: return "text";
        case TYPE_PROB: return "probability";
        case TYPE_VERDICT: return "verdict";
        case TYPE_DICT: return "dictionary";
        case TYPE_BATCH: return "batch";
        default: return "unknown";
    }
}

void print_table(SymbolTable *table, const char *label) {
    printf("\n--- Symbol Table: %s ---\n", label);
    Symbol *curr = table->head;
    while (curr) {
        printf("ID: %-15s | Type: %-10s | Scope: %s\n", 
               curr->name, type_to_string(curr->type), 
               curr->is_global ? "Global" : "Local");
        curr = curr->next;
    }
    printf("---------------------------\n");
}
