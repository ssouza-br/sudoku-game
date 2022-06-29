#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;
int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    if (argc > 2)
    {
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    BYTE *buffer = malloc(512);
    int counter = 0;
    char filename[9];
    bool new_jpg = false;
    int jpg_count = 0;
    char conteudo[600];
    typedef struct
    {
        int type = 0;//0 normal e 1 jpg
        int count = 0;
        FILE *file;
    }
    pacote;
    pacote pack;
    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            pack.type = 1;
        }
        if (pack.type == 1)
        {
            filename = sprintf()
            pack.file = fopen(filename, "w");
        }


        if (pack.type == 0)
        {
            fread(buffer, 1, BLOCK_SIZE, img0)
        }
    }
    free(buffer);
    fclose(file);
    if(file == NULL)
    {
        return 1;
    }
    printf("%s\n", argv[1]);
}