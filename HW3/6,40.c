#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char *data;
    struct node *next;
} node;

typedef node *list;

void add_node(list l, list cur)
{
    list new = (list)malloc(sizeof(node));
    new -> data = strdup(cur->data);
    new -> next = l;
    l = new;
}


list XOR_L1_L2(list L1, list L2)
{
    list L3 = NULL;
    for (list cur1 = L1; cur1 != NULL; cur1 = cur1 -> next)
    {
        int flag = 1;
        for (list cur2 = L2; cur2 != NULL; cur2 = cur2 -> next)
        {
            if (strcmp(cur1->data,cur2->data)==0)//функция выдаёт 0, есди есть совпадение
            {
                flag = 0;
                break;
            }
        }
        if (flag) add_node(L3,cur1);
    }
    for (list cur2 = L2; cur2 != NULL; cur2 = cur2->next)
    {
        int flag = 1;
        for (list cur1 = L1; cur1 != NULL; cur1 = cur1->next)
        {
            if (strcmp(cur2->data,cur1->data)==0)//функция выдаёт 0, есди есть совпадение
            {
                flag = 0;
                break;
            }
        }
        if (flag) add_node(L3,cur2);
    }
    return L3;
}
