#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
void grade(string text);

int main(void)
{
    string text = get_string("Text: ");
    // printf("%i letters\n", count_letters(text));
    // printf("%i words\n", count_words(text));
    // printf("%i sentences\n", count_sentences(text));
    grade(text);
}

int count_letters(string text)
{
    int len = strlen(text);
    int counter_letters = 0;
    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            counter_letters++;
        }
    }
    return counter_letters;
}

int count_words(string text)
{
    int len = strlen(text);
    int counter_words = 0;
    for (int i = 0; i < len; i++)
    {
        if (isspace(text[i]))
        {
            counter_words++;
        }
    }
    return counter_words + 1;
}

int count_sentences(string text)
{
    int len = strlen(text);
    int counter_sentences = 0;
    for (int i = 0; i < len; i++)
    {
        if (text[i] =='.' || text[i] =='!' || text[i] =='?')
        {
            counter_sentences++;
        }
    }
    return counter_sentences;
}

void grade(string text)
{
    int L = 100 * count_letters(text) / count_words(text); //L is the average number of letters per 100 words in the text
    int S = 100 * count_sentences(text) / count_words(text); //S is the average number of sentences per 100 words in the text
    float index = 0.0588 * L - 0.296 * S - 15.8;
    if (round(index) < 1)
    {
        printf("Before Grade 1");
    }
    else if (round(index) > 16)
    {
        printf("Grade 16+");
    }
    else{
        printf("Grade %f", round(index));
    }
}

