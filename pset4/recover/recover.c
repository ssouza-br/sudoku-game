#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    typedef uint8_t BYTE;
    int BLOCK_SIZE = 512;

    int counter = 0;
    char filename[9];
    bool new_jpg = false;
    int jpg_count = 0;
    char conteudo[600];
    typedef struct
    {
        int type;//0 normal e 1 jpg
        int count;
        int init;
        FILE *file;
        FILE *old_file;
    }
    pacote;
    pacote pack;

    BYTE *buffer = (BYTE*)malloc(512*sizeof(BYTE));

    // Check if the memory has been successfully
    // allocated by malloc or not
    if (buffer == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }

    if (argc > 2)
    {
        return 1;
    }
    //BYTE *buffer = malloc(512);

    // Dynamically allocate memory using malloc()

    FILE *file = fopen(argv[1], "r");

    pack.count = 0;
    pack.init = -1;
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
            pack.init = 0;
            sprintf(filename, "%03i.jpg", pack.count);
            pack.file = fopen(filename, "w");
            //FILE *img = fopen(filename, "w");
            //fwrite(buffer, 1, BLOCK_SIZE, img);
            fwrite(buffer, 1, BLOCK_SIZE, pack.file);
            pack.count++;
        }
        else if (pack.init == 0)
        {
        //printf("%s\n", pack.file);
            FILE *ptr = pack.file;
            fwrite(buffer, 1, BLOCK_SIZE, ptr);
        }
        //printf("pack type: %i\n", pack.type);
    }
    free(buffer);
    fclose(file);
    if(file == NULL)
    {
        return 1;
    }
}