#include <cs50.h>
#include <stdio.h>
#include <string.h>

string encrypt(string text, string key);

int main(int argc, string argv[])
{
    string key = argv[1];
    string text = get_string("plaintext:  ");
    printf("ciphertext: %s\n", encrypt(text,key));
}

string encrypt(string text, string key)
{
    char decode[26];
    char alphabet[26];
    string str_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int len = strlen(text);
    char new_text[len];
    char return_text[200];

    for (int i = 0; i < 26; i++)
    {
        decode[i] = key[i];
        alphabet[i] = str_alphabet[i];
    }

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (text[i] == alphabet[j])
            {
                new_text[i] = decode[j];
            }
        }
    }
    strcpy(return_text, new_text);
    return return_text;
}