#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;
int BLOCK_SIZE = 512;

BYTE *buffer = malloc(512);
int counter = 0;
char filename[9];
bool new_jpg = false;
int jpg_count = 0;
char conteudo[600];
typedef struct
{
    int type;//0 normal e 1 jpg
    int count;
    FILE *file;
    FILE *old_file;
}
pacote;
pacote pack;

int main(int argc, char *argv[])
{
    if (argc > 2)
    {
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    pack.count = 0;
    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            pack.type = 1;
        }
        else
        {
            pack.type = 0;
        }
        if (pack.type == 1)
        {
            fclose(pack.old_file);
            sprintf(filename, "%03i.jpg", pack.count);
            pack.file = fopen(filename, "w");
            fwrite(buffer, 1, BLOCK_SIZE, pack.file);
            pack.count++;
        }
        else
        {
            fwrite(buffer, 1, BLOCK_SIZE, pack.file);
        }
        printf("pack type: %i\n", pack.type);
    }
    free(buffer);
    fclose(file);
    if(file == NULL)
    {
        return 1;
    }
    printf("%s\n", argv[1]);
}