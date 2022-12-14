#include <cs50.h>
#include <stdio.h>

long int gen_decimals(int n);
int get_digits(long int n, int pos);
int len_number(long int n);
string card_type(long int n);
int check_sum_part1(long int n);
int check_sum_part2(long int n);
bool card_validation(long int n);

int main(void)
{
    long int n = get_long("Number: ");
    printf("%s\n", card_type(n));
}

long int gen_decimals(int n)
{
    long int res = 1;
    int i = n;
    while (i > 0)
    {
        res = res * 10;
        i--;
    }
    return res;
}

int get_digits(long int n, int pos)
{
    return (n % gen_decimals(pos) - n % gen_decimals(pos - 1)) / gen_decimals(pos - 1);
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
    for (int i = 2; i <= len_number(n); i = i + 2)
    {
        int double_digts = 2 * get_digits(n, i);
        if (len_number(double_digts) > 1)
        {
            sum = sum + get_digits(double_digts, 1) + get_digits(double_digts, 2);
        }
        else
        {
            sum = sum + double_digts;
        }
    }
    return sum;
}

int check_sum_part2(long int n)
{
    int sum = 0;
    for (int i = 1; i <= len_number(n); i = i + 2)
    {
        sum = sum + get_digits(n, i);
    }
    return sum;
}

bool card_validation(long int n)
{
    bool valid = false;
    int sum = check_sum_part1(n) + check_sum_part2(n);
    if (get_digits(sum, 1) == 0)
    {
        valid = true;
        return valid;
    }
    else
    {
        return valid;
    }
}

string card_type(long int n)
{
    int len = len_number(n);
    int first_pos = get_digits(n, len);
    int second_pos = get_digits(n, len - 1);

    if ((len == 13 || len == 16) && card_validation(n) && first_pos == 4)
    {
        return "VISA";
    }
    else if (len == 16 && card_validation(n) && first_pos == 5 && (second_pos == 1 || second_pos == 2 || second_pos == 3 ||
             second_pos == 4 || second_pos == 5))
    {
        return "MASTERCARD";
    }
    else if (len == 15  && card_validation(n) && first_pos == 3 && (second_pos == 4 || second_pos == 7))
    {
        return "AMEX";
    }
    else
    {
        return "INVALID";
    }
};