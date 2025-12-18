/*
 * File:    stack.c
 * Author:  zentut.com
 * Purpose: linked stack implementation
 */
#include <stdio.h>
#include <stdlib.h>

/*First, we declare the element of the stack:*/
struct node
{
    int data;
    struct node* next;
};
/*Second, we need to initialize the stack by 
setting the head pointer of the stack to NULL:*/
void init(struct node* head)
{
    head = NULL;
}
/*Third, to push an element into the stack, we create a new node, 
and point the stack pointer to the new node e.g., to push the first element:*/
struct node* push(struct node* head,int data)
{
    struct node* tmp = (struct node*)malloc(sizeof(struct node)); /*alokuję zmienną tymczasową*/
    if(tmp == NULL)
    {
        exit(0);
    }
    tmp->data = data;   /*przepisuję do niej dane*/
    tmp->next = head;   /*przepisuję do niej głowę*/
    head = tmp;         /*głowa teraz wzkaże na temp.*/
    return head;
}
/*To pop an element from the stack, we need to get the data of the element, 
point the stack pointer to the next element and remove it. 
The following picture illustrates how to pop the top element ( 5) from the stack.*/
struct node* pop(struct node *head,int *element)
{
    struct node* tmp = head;    /*alokuję head w tymczasuwce*/
    *element = head->data;      /*zapisuję wartość do elementu*/
    head = head->next;          /*zmieniam głowę na poprzedni/następny element*/
    free(tmp);                  /*uwalniam głowę przez tymczasuwkę*/
    return head;                
}
/*
    returns 1 if the stack is empty, otherwise returns 0
*/
int empty(struct node* head)
{
    return head == NULL ? 1 : 0;
}
/*To display the stack content, 
we traverse the stack elements from the first element to NULL.*/
void display(struct node* head)
{
    struct node *current; /*to proste */
    current = head;       /*teraźniejsza = głowa*/
    if(current!= NULL)    /*dopuki terażniejsza nie jest pusta*/
    {
        printf("Stack: ");
        do
        {
            printf("%d ",current->data); /*pokaż daną*/
            current = current->next;     /*zmień terażniejszą na następną*/
        }
        while (current!= NULL);
        printf("\n");
    }
    else
    {
        printf("The Stack is empty\n");
    }
 
}
