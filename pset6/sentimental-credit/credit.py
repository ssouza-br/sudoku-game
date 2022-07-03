number = input("Number: ")

def main():
    print(card_type(number))

def card_type(n):
    if (len(n) == 13 or len(n) == 16) and n[0] == "4":
        return "VISA"
    elif len(n) == 16 and n[0] == "5" and n[1] in range(1,6):
        return "MATERCARD"
    elif len(n) == 15  and n[0] == 3 and (n[1] == 4 or n[1] == 7):
        return "AMEX"
    else:
        return "INVALID"

def card_validation(n):
    valid = False
    int sum = check_sum_part1(n) + check_sum_part2(n);
    if (get_digits(sum, 1) == 0)
    {
        valid = true;
        return valid;
    }
    return valid

def check_sum(n):
    sum = 0
    for i in range(0, len(n), 2):
        if 2*int(n[i]) > 10:
            sum += 
        sum += 2*int(n[i])

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

main()