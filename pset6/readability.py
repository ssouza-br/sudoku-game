text = input("Text: ")

counter_letter = 0
counter_words = 0
counter_sentences = 0


for c in text:
    # counting letters
    if c.isalpha():
        counter_letter += 1
    # counting words
    if c == " ":
        counter_words += 1
    # counting sentences
    if c == "." or c == "!" or c == "?":
        counter_sentences+=1



