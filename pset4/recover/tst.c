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

int main(void)
{
pack.type = 1;
printf("%i\n", pack.type);

sprintf(filename, "%03i.jpg", pack.count);
pack.file = fopen(filename, "w");
fwrite(buffer, 1, BLOCK_SIZE, pack.file);

}