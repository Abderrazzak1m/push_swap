#include"push_swap.h"

int main(int argc, char **argv)
{
    Node *a;
    Node *b;
    int     i;
    int len;

    initialize(&a);
    initialize(&b);
    read_argv(argc, argv, &a);
    while(a != NULL)
    {
        printf("%d\n",a->data);
        a = a->next;
    }

}