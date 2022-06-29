#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct
{
    int type;//0 normal e 1 jpg
    int count;
    FILE *file;
    FILE *old_file;
}
pacote;
pacote pack;

char filename[9];
int main(void)
{
pack.type = 1;
pack.count = 0;
printf("%i\n", pack.type);

sprintf(filename, "%03i.txt", pack.count);
pack.file = fopen(filename, "w");
char *text = "teste louco";
fprintf(text, sizeof(text), 50, pack.file)
//fwrite(buffer, 1, BLOCK_SIZE, pack.file);

}