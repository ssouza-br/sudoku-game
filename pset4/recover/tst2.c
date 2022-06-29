#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>




int main(void)
{
    int *buffer;
    buffer = (int*)malloc(20 * sizeof(int));

    // Check if the memory has been successfully
    // allocated by malloc or not
    if (buffer == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
}