#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc > 2)
    {
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    buffer = malloc(512);
    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {


    }



    fclose(file);
    if(file == NULL)
    {
        return 1;
    }
    printf("%s\n", argv[1]);
}