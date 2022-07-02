#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(void)
{
    node *lista = NULL;

    node *n = malloc(sizeof(node));
    n->number = 1;
    n->next = NULL;

    lista = n;

    n = malloc(sizeof(node));
    n->number = 2;
    n->next = NULL;

    lista->next = n;

    n = malloc(sizeof(node));
    n->number = 3;
    n->next = NULL;

    lista->next->next = n;
    //free(n);

    for (node *tmp = lista; tmp != NULL; tmp=tmp->next)
    {
        printf("%i\n", tmp->number);
    }

    //unload
    

}
