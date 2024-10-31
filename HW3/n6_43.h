#ifndef n_43_h
#define n_43_h
#include <stdlib.h>

typedef struct inode {
    void *data;
    struct inode *next;
} inode;

typedef inode *stack;

void push_stack(stack *st, void *data);

void *pop_stack(stack *st);

void clear_ststack(stack *st);

#endif
