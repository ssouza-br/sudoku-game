#include <cs50.h>
#include <stdio.h>

void horizontal_block(int n);

int main(void){
    do{
        int n = get_int("Height: ")
    }
    while()
    //printf("#  #\n");
    horizontal_block(2);
}

void parts_block(int n){
    for(int i = 0;i<n;i++){
        printf("#");
    }
}

void horizontal_block(int n){
    parts_block(n);
    printf("  ");
    parts_block(n);
}