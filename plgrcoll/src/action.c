#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "action.h"

void add_word_node(WORD_NODE *head, char* token)
{
    WORD_NODE *p = head;
    while(p != NULL) {
        if (strcmp(p->v, token) == 0) {
            return;
        }
        if (p->n == NULL) {
            WORD_NODE *np = create_word_node(token);
            p->n = np;
            return;
        }
        p = p->n;
    }
}

WORD_NODE *create_word_node(char* token)
{
    WORD_NODE *p = malloc(sizeof(WORD_NODE));

    size_t len = strlen(token);
    p->v = malloc(len+1);
    strcpy(p->v, token);

    p->n = NULL;
    
    return p;
}

void print_word_node(WORD_NODE *head)
{
    WORD_NODE *p = head;
    while(p != NULL) {
        printf("%s\n", p->v);
        p = p->n;
    }
}

void free_word_node(WORD_NODE *head)
{
    WORD_NODE *p = head;
    WORD_NODE *np;
    while(p != NULL) {
        np = p->n;
        free(p->v);
        free(p);
        p = np;
    }
}

