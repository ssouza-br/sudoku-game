#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long int n = get_long("Number: ");
    printf("%li\n", n);
    printf("%li\n", n%10);
    printf("%li\n", (n%100- n%10)/10);
    printf("%li\n", (n%1000 - n%100)/100);

}

int get_digits(long int n)
{
    
}

// string luhns_algorithm(long int n)
// {

// }