#include <cs50.h>
#include <stdio.h>

void horizontal_block(int n);

int main(void){
    //printf("#  #\n");
    horizontal_block(2);
}

void horizontal_block(int n){
    string ptr = "##";
    printf("%s",3*ptr);
}