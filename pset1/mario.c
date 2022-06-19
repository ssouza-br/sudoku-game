#include <cs50.h>
#include <stdio.h>

void horizontal_block(int n);

int main(void){
    do{
        int n = get_int("Height: ");
    }
    while(n>=1 && n<=8)
    for(int i =0;i<n;i++){
        horizontal_block(n);
    }

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