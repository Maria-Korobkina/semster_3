#include "n6_43_h"

void push_stack(stack *st, void *value)
{
    stack new = (stack)malloc(sizeof(inode));
    new -> data = value;
    new -> next = *st;
    *st = new;
}

void *pop_stack(stack *st)
{
    if (*st == NULL) return NULL;
    stack first = *st;
    void *value = first -> data;
    *st = (*st) -> next;
    free(first);
    return value;
}

void clear_stack(stack *st)
{
    stack buff = *st;
    *st = (*st) -> next;
    for (; *st != NULL; *st = (*st) -> next)
    {
        free(buff);
        buff = *st;
    }
}
