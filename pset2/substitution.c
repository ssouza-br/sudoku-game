#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(string text, string key);

int main(int argc, string argv[])
{
    string key = argv[1];
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
    }
    else
    {
        string text = get_string("plaintext:  ");
        encrypt(text,key);
    }
}

void encrypt(string text, string key)
{
    char decode[26];
    char alphabet[26];
    string str_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int len = strlen(text);
    char new_text[len];
    char return_text[len];

    for (int i = 0; i < 26; i++)
    {
        decode[i] = key[i];
        alphabet[i] = str_alphabet[i];
    }

    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if (text[i] == alphabet[j])
                {
                    new_text[i] = decode[j];
                }
                else if (text[i] == tolower(alphabet[j]))
                {
                    new_text[i] = decode[j];
                }
            }
        }
        else
        {
            new_text[i] = text[i];
        }
    }
    strcpy(return_text, new_text);
    printf("ciphertext: %s\n", return_text);
}