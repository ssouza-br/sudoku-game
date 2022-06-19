#include <cs50.h>
#include <stdio.h>

long int gen_decimals(int n);
int get_digits(long int n, int pos);
int len_number(long int n);
string card_type(long int n);
int check_sum_part1(long int n);

int main(void)
{
    long int n = get_long("Number: ");
    printf("%s\n",card_type(n));
    printf("%i\n",check_sum(n));
   // int pos = get_int("position: ");
   // printf("%i\n", get_digits(n,pos));
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
    return (n%gen_decimals(pos) - n%gen_decimals(pos-1)) / gen_decimals(pos-1);
}

int len_number(long int n)
{
    long int res = 1;
    int i = 0;
    while (res >= 0)
    {
        res = n - gen_decimals(i);
        i++;
    }
    return i - 1;
}

int check_sum_part1(long int n)
{
    int sum = 0;
    for (int i = len_number(n); i > 0;i=i-2)
    {
        int double_digts = 2*get_digits(n, i);
        if (len_number(double_digts) > 1)
        {
            sum = sum + get_digits(double_digts, 1) + get_digits(double_digts, 2);
        }
        else{
            sum = sum + double_digts;
        }

        printf("position: %i\n", i);
        printf("digito: %i\n", get_digits(n, i));
        printf("item soma: %i\n", 2*get_digits(n, i));
    }
    return sum;
}

int check_sum_part2(long int n)
{
    int sum = 0;
    for (int i = len_number(n) - 1; i > 0;i=i-2)
    {
        int double_digts = 2*get_digits(n, i);
        if (len_number(double_digts) > 1)
        {
            sum = sum + get_digits(double_digts, 1) + get_digits(double_digts, 2);
        }
        else{
            sum = sum + double_digts;
        }

        printf("position: %i\n", i);
        printf("digito: %i\n", get_digits(n, i));
        printf("item soma: %i\n", 2*get_digits(n, i));
    }
    return sum;
}

string card_type(long int n)
{
    int len = len_number(n);
    int first_pos = get_digits(n, len);
    int second_pos = get_digits(n, len - 1);
    // printf("%i\n", len);
    // printf("%i\n", first_pos);
    // printf("%i\n", second_pos);

    if (first_pos == 4)
    {
        return "VISA\n";
    }
    else if (first_pos == 5 && (second_pos == 1 || second_pos == 2 || second_pos == 3 || second_pos == 4 || second_pos == 5))
    {
        return "MASTERCARD\n";
    }
    else if (first_pos == 3 && (second_pos == 4 || second_pos == 7))
    {
        return "AMEX\n";
    }
    else{
        return "TRISTE\n";
    }
};