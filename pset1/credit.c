#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long int n = get_long("Number: ");
    printf("%li\n", n);
    printf("%li\n", n%10);
    printf("%li\n", (n%100- n%10)/10);
    printf("%li\n", (n%1000 - n%100)/100);
    printf("%li\n", (n%10000 - n%1000)/1000);


}

int gen_tens(int n)
{
    long int res;
    int i = n;
    while(i > 0)
    {

    }
    return
}

int get_digits(long int n, int pos)
{
    return n%10 - n%1
}

// string luhns_algorithm(long int n)
// {

// }