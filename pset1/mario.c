#include <cs50.h>
#include <stdio.h>

void horizontal_block(int n, int m);

int main(void)
{
    int m;
    do
    {
        m = get_int("Height: ");
        if (m <= 8 && m > 0)
        {
            for (int i = 1; i <= m; i++)
            {
                horizontal_block(i, m);
                printf("\n");
            }
        }
    }
    while (m <= 0 || m > 8);
}

void parts_block(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}

void parts_space(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

void horizontal_block(int n, int m)
{
    parts_space(m - n);
    parts_block(n);
    printf("  ");
    parts_block(n);
}