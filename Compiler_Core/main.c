#include <stdio.h>
#include <stdlib.h>
#include "symbol_table.h"
#include "quads.h"
#include "../Analyse_Syntaxosemantique/sentinel.tab.h"

extern FILE *yyin;
extern int yyparse();
extern SymbolTable *config_table;
extern SymbolTable *pipeline_table;
extern QuadList *quads;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (!f) {
        perror("Error opening file");
        return 1;
    }

    yyin = f;

    // Initialize structures
    config_table = create_table();
    pipeline_table = create_table();
    quads = create_quad_list();

    printf("--- SENTINEL COMPILER START ---\n");
    
    if (yyparse() == 0) {
        printf("\n✅ Compilation Successful!\n");
        
        print_table(config_table, "CONFIG (Global)");
        print_table(pipeline_table, "PIPELINE (Local)");
        print_quads(quads);
    } else {
        printf("\n❌ Compilation Failed.\n");
    }

    fclose(f);
    return 0;
}
