#include"push_swap.h"

Node    *newNode(int x)
{
    Node *newnode;

    newnode = (Node*)malloc(sizeof(Node));
    if (newnode != NULL)
    {
        newnode->data = x;
        newnode->next = NULL;
    }
    return (newnode);

}
void    initialize(Node **stack)
{
    *stack = NULL;
}

void    push(Node **stack, int num)/*empiler nouvel element*/
{
    Node *p;

    p = newNode(num);
    p->next = *stack;
    *stack = p;
}

int pop(Node **stack)/*depiler sommet de pile*/
{
    Node *forfree;
    int top;
    if(*stack == NULL)
    {
        return -1;/*Operation impossible : pile vide*/
    }
    else
    {
        forfree = *stack;
        top = (*stack)->data;
        *stack = (*stack)->next;
        free(forfree);
        return top;
    }
}

int top(Node *stack)/* Sommet de la pile*/
{
    if(stack == NULL)
    {
        return -1;/*Erreur : pile vide*/
    }
else
    return stack->data;
}