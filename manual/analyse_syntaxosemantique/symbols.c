#include "symbols.h"
#include <stdlib.h>
#include <string.h>

ManualSymbolTable* create_manual_table() {
    ManualSymbolTable *t = (ManualSymbolTable*)malloc(sizeof(ManualSymbolTable));
    t->head = NULL;
    return t;
}

void insert_manual_symbol(ManualSymbolTable *list, char *name, DataType type, int is_global) {
    ManualSymbol *s = (ManualSymbol*)malloc(sizeof(ManualSymbol));
    strcpy(s->name, name);
    s->type = type;
    s->is_global = is_global;
    s->next = list->head;
    list->head = s;
}

ManualSymbol* lookup_manual_symbol(ManualSymbolTable *config, ManualSymbolTable *pipeline, char *name) {
    if (pipeline) {
        ManualSymbol *curr = pipeline->head;
        while (curr) {
            if (strcmp(curr->name, name) == 0) return curr;
            curr = curr->next;
        }
    }
    if (config) {
        ManualSymbol *curr = config->head;
        while (curr) {
            if (strcmp(curr->name, name) == 0) return curr;
            curr = curr->next;
        }
    }
    return NULL;
}
