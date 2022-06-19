#include <cs50.h>
#include <stdio.h>

void horizontal_block(int n);

int main(void){
    int n;
    do{
        n = get_int("Height: ");
        for(int i =0;i<n;i++){
            horizontal_block(n);
        }
    }
    while(n<=1 && n>=8);

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