#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char *data;
    struct node *next;
} node;

typedef node *list;

void add_node1(list *l, char *value)
{
    list new = (list)malloc(sizeof(node));
    new->data = strdup(value);
    new->next = *l;
    *l = new;
}

void print_list(list l)
{
    list cur = l;
    while (cur != NULL)
    {
        printf("%s ", cur->data); 
        cur = cur->next;
    }
    printf("\n");
}

list XOR_L1_L2(list L1, list L2)
{
    list L3 = NULL;
    for (list cur1 = L1; cur1 != NULL; cur1 = cur1->next)
    {
        int flag1 = 1;
        for (list cur2 = L2; cur2 != NULL; cur2 = cur2->next)
        {
            if (strcmp(cur1->data, cur2->data) == 0)
            {
                flag1 = 0;
                break;
            }
        }
        if (flag1 == 1)
        {
            node *buf = (node *)malloc(sizeof(node));
            buf->data = strdup(cur1->data);
            buf->next = L3;
            L3 = buf;
        }
    }
    for (list cur2 = L2; cur2 != NULL; cur2 = cur2->next)
    {
        int flag2 = 1;
        for (list cur1 = L1; cur1 != NULL; cur1 = cur1->next)
        {
            if (strcmp(cur2->data, cur1->data) == 0)
            {
                flag2 = 0;
                break;
            }
        }
        if (flag2 == 1)
        {
            node *buf = (node *)malloc(sizeof(node));
            buf->data = strdup(cur2->data);
            buf->next = L3;
            L3 = buf;
        }
    }
    return L3;
}

int main(void)
{
    list l1 = NULL;
    char *val1[] = {"1", "2", "3", "4"};
    for (int i = 0; i < 4; i++) add_node1(&l1, val1[i]);
    print_list(l1);
    
    list l2 = NULL;
    char *val2[] = {"1", "6", "3"};
    for (int i = 0; i < 3; i++) add_node1(&l2, val2[i]);
    print_list(l2);
    
    list l3 = XOR_L1_L2(l1, l2);
    print_list(l3);
    
    return 0;
}
