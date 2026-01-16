#ifndef QUADS_H
#define QUADS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Quad {
    char *op;
    char *arg1;
    char *arg2;
    char *res;
    struct Quad *next;
} Quad;

typedef struct {
    Quad *head;
    Quad *tail;
    int count;
} QuadList;

QuadList* create_quad_list();
void add_quad(QuadList *list, char *op, char *arg1, char *arg2, char *res);
char* new_temp();
char* new_label();
void print_quads(QuadList *list);

#endif
