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
        int count;
        char file[9];
    }
    pacote;
    pacote pack;
    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        sprintf(filename, "%03i.jpg", counter);
        printf("meu nome de arquivo: %s\n", filename);
        FILE *img0 = fopen(filename, "w");

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                pack.count++;
                new_jpg = true;
                fwrite(buffer, 1, BLOCK_SIZE, img0);
                //counter++;
            }
        else if (new_jpg)
        {
            fwrite(buffer, 1, BLOCK_SIZE, img0);
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