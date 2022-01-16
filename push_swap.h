
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define STACKSIZE 5000
#define VALUE_OUT -1

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

void    initialize(Node **stack);
void    push(Node **stack, int num);
int     pop(Node **stack);
int     top(Node *stack);
int     ft_atoi(const char *str);
void	ft_putstr(char *s);
int     ft_strlen(const char *s);
Node    *newNode(int x);
void    swap(Node **a);
void    ss(Node **a, Node **b);
void    p(Node **a, Node **b);
void    r(Node **a);
void    rr(Node **a);
char	*ft_strdup(char *src);
char	**ft_split(char const *s, char c);
char    *ft_strjoin(char const *s1, char const *s2);
//char	**get_arg(int argc, char **argv);
void    read_argv(int argc, char **argv,Node **a);


#endif