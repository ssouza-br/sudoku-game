text = input("Text: ")

counter_letter = 0

//counting letters
for c in text:
    if c.isalpha():
        counter_letter += 1
