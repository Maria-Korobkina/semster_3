#ifndef n6_42_h
#define n6_42_h
#include <stdlib.h>

typedef struct node
{
    void *data;
    struct node *next;
} node;

typedef node *queue;

void putqu(queue *q, void *data);

void *getqu(queue *q);

int sizequ(queue q);

void clearqu(queue *q);
#endif 
