#include "quads.h"

static int temp_count = 0;
static int label_count = 0;

QuadList* create_quad_list() {
    QuadList *list = (QuadList*)malloc(sizeof(QuadList));
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
    return list;
}

void add_quad(QuadList *list, char *op, char *arg1, char *arg2, char *res) {
    Quad *q = (Quad*)malloc(sizeof(Quad));
    q->op = op ? strdup(op) : strdup("");
    q->arg1 = arg1 ? strdup(arg1) : strdup("");
    q->arg2 = arg2 ? strdup(arg2) : strdup("");
    q->res = res ? strdup(res) : strdup("");
    q->next = NULL;

    if (list->tail) {
        list->tail->next = q;
        list->tail = q;
    } else {
        list->head = q;
        list->tail = q;
    }
    list->count++;
}

char* new_temp() {
    char *name = (char*)malloc(20);
    sprintf(name, "T%d", temp_count++);
    return name;
}

char* new_label() {
    char *name = (char*)malloc(20);
    sprintf(name, "L%d", label_count++);
    return name;
}

void print_quads(QuadList *list) {
    printf("\n--- Intermediate Code (Quadruplets) ---\n");
    Quad *curr = list->head;
    int i = 0;
    while (curr) {
        printf("%d: (%s, %s, %s, %s)\n", i++, curr->op, curr->arg1, curr->arg2, curr->res);
        curr = curr->next;
    }
    printf("--------------------------------------\n");
}
