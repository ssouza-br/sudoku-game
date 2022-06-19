#include <cs50.h>
#include <stdio.h>

long int gen_decimals(int n);

int main(void)
{
    long int n = get_long("Number: ");
    printf("%li\n", gen_decimals(n));
    // printf("%li\n", n);
    // printf("%li\n", n%10);
    // printf("%li\n", (n%100- n%10)/10);
    // printf("%li\n", (n%1000 - n%100)/100);
    // printf("%li\n", (n%10000 - n%1000)/1000);
}

long int gen_decimals(int n)
{
    long int res = 1;
    int i = n;
    while(i > 0)
    {
        res = res*10;
        i--;
    }
    return res;
}

int get_digits(long int n, int pos)
{
    return n%10 - n%1;
}

// string luhns_algorithm(long int n)
// {

// }