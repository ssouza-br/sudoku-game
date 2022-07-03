text = input("Text: ")

counter_letters = 0
counter_words = 0
counter_sentences = 0


for c in text:
    # counting letters
    if c.isalpha():
        counter_letters += 1
    # counting words
    if c == " ":
        counter_words += 1
    # counting sentences
    if c == "." or c == "!" or c == "?":
        counter_sentences+=1

def grade():
    L = 100 * counter_letters / (counter_words + 1) # L is the average number of letters per 100 words in the text
    S = 100 * counter_sentences / (counter_words + 1) # S is the average number of sentences per 100 words in the text

    index = 0.0588 * L - 0.296 * S - 15.8

    if (round(index) < 1):
        print("Before Grade 1")
    elif (round(index) > 16):
        print("Grade 16+")
    else:
        print(f"Grade {round(index)}")

#print(f" l: {counter_letters} w: {counter_words} s: {counter_sentences}")
grade()