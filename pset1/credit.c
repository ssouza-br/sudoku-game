#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long int n = get_long("Number: ");
    printf("%li\n", n);
    printf("%li\n", n%1);
    printf("%li\n", n%10);
    printf("%li\n", n%100);

}

// string luhns_algorithm(long int n)
// {

// }