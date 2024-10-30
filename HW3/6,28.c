#include <stdio.h>
#include <stdlib.h>

typedef struct inode
{
    double *data;
    struct inode *next;
} inode;

typedef inode *list;

void swap_first_last(list *l)
{
    if ((*l == NULL) || ((*l) -> next == NULL)) return;
    list buffer = *l, last;
    for (; buffer -> next -> next != NULL; buffer = buffer -> next);
    last = buffer -> next;
    last -> next = (*l) -> next;
    (*l) -> next = NULL;
    buffer -> next  = *l;
    *l = last;
}

void delete_first_occur1(list *l, double *el)
{
    if (*l == NULL) return;
    for (; (*l != NULL) && ((*l) -> data != el); l = &((*l) -> next));
    if (*l == NULL) return;
    list buffer = *l;
    (*l) = (*l) -> next;
    free(buffer);
}

void delele_first_occur2(list l, double *el)
{
    if (l == NULL) return;
    for (; (l != NULL) && (l -> data != el); l = l -> next);
    if (l == NULL) return;
    list buffer = l;
    l = l -> next;
    free(buffer);
}

void delete_elem1(list *l, double *el)
{
    if (*l == NULL) return;
    while (*l != NULL)
    {
        for (;(*l != NULL) && ((*l) -> data != el); l = &((*l) -> next));
        if (*l == NULL) return;
        list buffer = *l;
        *l = (*l) -> next;
        free(buffer);
    }
}

void delete_elem2(list l, double *el)
{
    if (l == NULL) return;
    while (l != NULL)
    {
        for (;(l != NULL) && (l -> data != el); l = l -> next);
        if (l == NULL) return;     
        list buffer = l;
        l = l -> next;
        free(buffer);
    }
}

void double_el(list *l, double *el)
{
    if (*l == NULL) return;
    while (*l != NULL)
    {
        for (;(*l != NULL) && ((*l) -> data != el); l = &((*l) -> next));
        if (l == NULL) return;
        list buffer = (list)malloc(sizeof(inode));
        buffer -> data = el;
        buffer -> next = (*l) -> next;
        (*l) -> next = buffer;
    } 
}

void add_node(list *l, double *value)
{
    list new = (list)malloc(sizeof(inode));
    new -> data = value;
    new -> next = *l;
    *l = new;
}

void print_list(list *l)
{
    list cur = *l;
    while (cur -> next != NULL)
    {
        printf("%3.1f ", *cur -> data);
        cur = cur -> next;
    }
    printf("\n");
}


int main(void)
{
    list l = NULL;
    double val[] = {1.0, 2.0, 2.0, 3.0, 3.0, 3.0, 4.0, 4.0, 4.0, 4.0};
    for (int i=0 ; i<10; i++) add_node(&l, &val[i]);
    print_list(&l);
    swap_first_last(&l);
    print_list(&l);
    delete_elem1(&l, &val[3]);
    print_list(&l);
    return 0;
}
