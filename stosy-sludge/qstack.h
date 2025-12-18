/*
 * File:    stack.h
 * Author:  zentut.com
 * Purpose: linked stack header file
 */
#ifndef LINKEDSTACK_H_INCLUDED
#define LINKEDSTACK_H_INCLUDED

struct node
{
    int data;
    struct node* next;
};
int empty(struct node *head);
struct node* push(struct node *head,int data);
struct node* pop(struct node *head,int *data);
void init(struct node* head);
void display(struct node* head);
#endif // LINKEDSTACK_H_INCLUDED