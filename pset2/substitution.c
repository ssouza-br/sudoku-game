#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(string text, string key);
bool key_valid(string key);

int main(int argc, string argv[])
{
    string key = argv[1];
    if (argc != 2 || !key_valid(key))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        string text = get_string("plaintext:  ");
        encrypt(text, key);
    }
}

void encrypt(string text, string key)
{
    char decode[26];
    char upper_alphabet[26];
    string str_upper_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int len = strlen(text);
    char new_text[len + 1];
    char return_text[len];

    for (int i = 0; i < 26; i++)
    {
        decode[i] = toupper(key[i]);
        upper_alphabet[i] = str_upper_alphabet[i];
    }

    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if (text[i] == upper_alphabet[j])
                {
                    new_text[i] = decode[j];
                }
                else if (text[i] == tolower(upper_alphabet[j]))
                {
                    new_text[i] = tolower(decode[j]);
                }
            }
        }
        else
        {
            new_text[i] = text[i];
        }
    }
    new_text[len] = '\0';
    printf("ciphertext: %s\n", new_text);
}

bool key_valid(string key)
{
    int len = strlen(key);

    for (int i = 0; i < len; i++)
    {
        if (!isalpha(key[i])){
            return false;
        }
    }
    return true;
}

bool check_key_duplicity(string key)
{
    typedef struct
    {
        char letter;
        int count
    } letter
    int len = strlen(key);
    dictionary = letter[len];

    for (int i = 0; i < len; i++)
    {
        if (dictionary[i].letter == '')
        {
            dictionary[i].letter = key[i];
            dictionary[i].count = 1;
        }
        else
        {
            dictionary[i].count = dictionary[i].count + 1;
        }
    }
}