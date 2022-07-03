text = input("Text: ")

counter_letter = 0
counter_words = 0

# counting letters
for c in text:
    if c.isalpha():
        counter_letter += 1

# counting words
for word in text.split(" "):
    counter_words += 1

print(counter_letter, counter_words)