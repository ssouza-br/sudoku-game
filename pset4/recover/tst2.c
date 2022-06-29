#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>





typedef uint8_t BYTE;

int main(void)
{
    int *buffer;

    buffer = (BYTE*)malloc(512*sizeof(BYTE));


    // Check if the memory has been successfully
    // allocated by malloc or not
    if (buffer == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
}