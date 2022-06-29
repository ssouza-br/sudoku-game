#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


typedef uint8_t BYTE;
int *buffer;

buffer = (int*)malloc(20 * sizeof(int));

// Check if the memory has been successfully
// allocated by malloc or not
if (buffer == NULL) {
    printf("Memory not allocated.\n");
    exit(0);
}

int main(void)
{

}