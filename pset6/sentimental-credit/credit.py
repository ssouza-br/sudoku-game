number = input("Number: ")

def main():
    print(card_type(number))

def card_type(n):
    if card_validation:
        if (len(n) == 13 or len(n) == 16) and n[0] == "4":
            return "VISA"
        elif len(n) == 16 and n[0] == "5" and (int(n[1]) in range(1,6)):
            return "MATERCARD"
        elif len(n) == 15  and n[0] == "3" and (n[1] == "4" or n[1] == "7"):
            return "AMEX"
        else:
            return "INVALID"
    return "INVALID"

def card_validation(n):
    sum = 0

    for i in range(len(n)-1, 0, -2):
        if 2*int(n[i]) > 10:
            sum += 2*int(n[i]) // 10 + 2*int(n[i]) % 10
        else:
            sum += 2*int(n[i])


    for i in range(len(n), 0, -2):
        sum += int(n[i])


    if sum % 10 == 0:
        return True
    return False

main()