#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    string key = argv[1]
}

string encrypt(string text, string key)
{
    char decode[26];
    char alphabet = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']

    for (int i = 0; i < 26; i++)
    {
        decode[i] = key[i];
    }
    for (int i = 0, int len = strlen(text); i < len; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (text[i] == alpabet[j])
            {

            }
        }

        decode[i] = key[i];
    }
}