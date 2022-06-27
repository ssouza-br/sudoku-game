#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc > 2)
    {
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    printf("%s\n", argv[1]);

    if(file == NULL)
    {
        return 1;
    }
}