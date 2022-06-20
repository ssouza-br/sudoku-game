#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int count_letters(string text);
int count_words(string text);

int main(void)
{
    string text = get_string("Text: ");
    printf("%i letters\n", count_letters(text));
    printf("%i words\n", count_words(text));
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
        if (strcmp(text[i], " ") == 0)
        {
            counter_words++;
        }
    }
    return counter_words;
}

