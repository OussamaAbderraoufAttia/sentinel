#include <stdio.h>
#include <stdlib.h>
#include "analyse_syntaxosemantique/parser.h"

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

    printf("--- SENTINEL MANUAL COMPILER START ---\n");
    init_parser(f);
    parse_program();
    
    printf("\n✅ Manual Compilation Syntax Phase Successful!\n");

    fclose(f);
    return 0;
}
