#include "lexer_common.h"

static int state_counter = 0;

State* create_state(int is_final, TokenType type) {
    State *s = (State*)malloc(sizeof(State));
    s->id = state_counter++;
    s->transitions = NULL;
    s->is_final = is_final;
    s->token_type = type;
    return s;
}

CharSet* create_charset(char start, char end) {
    CharSet *cs = (CharSet*)malloc(sizeof(CharSet));
    cs->start = start;
    cs->end = end;
    cs->next = NULL;
    return cs;
}

void add_transition(State *from, State *to, CharSet *cs) {
    Transition *t = (Transition*)malloc(sizeof(Transition));
    t->chars = cs;
    t->to = to;
    t->next = from->transitions;
    from->transitions = t;
}

AFN* build_string_afn(const char *str, TokenType type) {
    AFN *afn = (AFN*)malloc(sizeof(AFN));
    afn->start = create_state(0, TOK_ERROR);
    State *curr = afn->start;

    for (int i = 0; str[i]; i++) {
        State *next = create_state(0, TOK_ERROR);
        add_transition(curr, next, create_charset(str[i], str[i]));
        curr = next;
    }
    curr->is_final = 1;
    curr->token_type = type;
    afn->end = curr;
    return afn;
}

AFN* build_regex_id_afn() {
    AFN *afn = (AFN*)malloc(sizeof(AFN));
    State *s0 = create_state(0, TOK_ERROR);
    State *s1 = create_state(1, TOK_ID);
    
    // [a-zA-Z_]
    CharSet *cs1 = create_charset('a', 'z');
    cs1->next = create_charset('A', 'Z');
    cs1->next->next = create_charset('_', '_');
    add_transition(s0, s1, cs1);

    // [a-zA-Z0-9_]*
    CharSet *cs2 = create_charset('a', 'z');
    cs2->next = create_charset('A', 'Z');
    cs2->next->next = create_charset('0', '9');
    cs2->next->next->next = create_charset('_', '_');
    add_transition(s1, s1, cs2);

    afn->start = s0;
    afn->end = s1;
    return afn;
}

AFN* build_regex_int_afn() {
    AFN *afn = (AFN*)malloc(sizeof(AFN));
    State *s0 = create_state(0, TOK_ERROR);
    State *s1 = create_state(1, TOK_INT_LIT);

    // [0-9]+
    add_transition(s0, s1, create_charset('0', '9'));
    add_transition(s1, s1, create_charset('0', '9'));

    afn->start = s0;
    afn->end = s1;
    return afn;
}

AFN* build_regex_float_afn() {
    AFN *afn = (AFN*)malloc(sizeof(AFN));
    State *s0 = create_state(0, TOK_ERROR);
    State *s1 = create_state(0, TOK_ERROR);
    State *s2 = create_state(0, TOK_ERROR);
    State *s3 = create_state(1, TOK_FLOAT_LIT);

    // [0-9]+\.[0-9]+
    add_transition(s0, s1, create_charset('0', '9'));
    add_transition(s1, s1, create_charset('0', '9'));
    add_transition(s1, s2, create_charset('.', '.'));
    add_transition(s2, s3, create_charset('0', '9'));
    add_transition(s3, s3, create_charset('0', '9'));

    afn->start = s0;
    afn->end = s3;
    return afn;
}

AFN* build_regex_string_afn() {
    AFN *afn = (AFN*)malloc(sizeof(AFN));
    State *s0 = create_state(0, TOK_ERROR);
    State *s1 = create_state(0, TOK_ERROR);
    State *s2 = create_state(1, TOK_STRING_LIT);

    // " [^"]* "
    add_transition(s0, s1, create_charset('"', '"'));
    
    CharSet *cs = create_charset(32, 33); // Space and !
    cs->next = create_charset(35, 126);   // # to ~
    add_transition(s1, s1, cs);
    
    add_transition(s1, s2, create_charset('"', '"'));

    afn->start = s0;
    afn->end = s2;
    return afn;
}
