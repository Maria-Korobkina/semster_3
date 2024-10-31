#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data 
{    
    double f; 
    char *s[2]; 
};
struct node 
{
    struct data *p;
    struct node *next; 
};


struct node* copy_list(struct node* head)
{
    if (head == NULL) return NULL;
    struct node* new_head = (struct node*)malloc(sizeof(struct node));
    if (new_head == NULL) return NULL;
    new_head->p = (struct data*)malloc(sizeof(struct data));
    if (new_head->p == NULL)
    {
        free(new_head);
        return NULL;
    }
    new_head->p->f = head->p->f;
    for (int i = 0; i < 2; i++)
    {   
        new_head->p->s[i] = (char*)malloc(strlen(head->p->s[i]) + 1); 
        if (new_head->p->s[i] == NULL)
        {   
            free(new_head->p);
            free(new_head);            
            return NULL;
        }       
        strcpy(new_head->p->s[i], head->p->s[i]);
    }
    new_head->next = copy_list(head->next);
    return new_head;
};

void print_list(struct node* head) 
{
    while (head != NULL) 
    {        
        printf("f: %f, s[0]: %s, s[1]: %s\n", head->p->f, head->p->s[0], head->p->s[1]);
        head = head->next;    
    }
}

int main(void)
{
    struct node* head = (struct node*)malloc(sizeof(struct node)); 
    head->p = (struct data*)malloc(sizeof(struct data));
    head->p->f = 3.14;
    head->p->s[0] = strdup("abc");
    head->p->s[1] = strdup("hello");
    head->next = NULL;
    struct node* second = (struct node*)malloc(sizeof(struct node));  
    second->p = (struct data*)malloc(sizeof(struct data));
    second->p->f = 2.71;
    second->p->s[0] = strdup("Foo");
    second->p->s[1] = strdup("Bar");
    second->next = NULL;
    head->next = second;      //    cвязываем узлы
    struct node* third = (struct node*)malloc(sizeof(struct node));
    third->p = (struct data*)malloc(sizeof(struct data));
    third->p->f = 1.55;
    third->p->s[0] = strdup("Hello");
    third->p->s[1] = strdup("World");
    third->next = NULL;
    second->next = third;
    printf("input list\n");    
    print_list(head); 
    struct node* copied_list = copy_list(head); 
    printf("copied list\n");
    print_list(copied_list);
    //free_list(head);  
    //free_list(copied_list);
    return 0;
}
