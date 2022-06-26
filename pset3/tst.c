#include <stdio.h>
void swap(int *a, int *b);
void sort_pairs(int lista_deord[]);
int main(void)
{
    int lista[] = {1, 9, 5};
    sort_pairs(lista);
    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", lista[i]);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_pairs(int lista_deord[])
{
    int max_strength = 0;
    int temp = 0;

    for (int k = 0; k < 3 - 1; k++)
    {
        for (int i = k; i < 3; i++)
        {
            //lista completa
            if (lista_deord[i] > max_strength)
            {
                max_strength = lista_deord[i];
                swap(&lista_deord[k], &lista_deord[i]);
            }
        }
        max_strength = 0;
    }
}
