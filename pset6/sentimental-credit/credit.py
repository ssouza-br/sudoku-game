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



main()