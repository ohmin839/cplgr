#if !defined(PLGRCOLL_ACTION_H)
#define PLGRCOLL_ACTION_H

typedef struct word_node {
    char *v;
    struct word_node *n;
} WORD_NODE;

WORD_NODE *create_word_node(char* token);
void add_word_node(WORD_NODE *head, char* token);
void print_word_node(WORD_NODE *head);
void free_word_node(WORD_NODE *head);

#endif
