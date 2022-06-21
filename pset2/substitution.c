#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(string text, string key);

int main(int argc, string argv[])
{
    string key = argv[1];
    if (argc != 2)
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
        //printf("%s\n", text);
        encrypt(text,key);
    }
}

void encrypt(string text, string key)
{
    char decode[26];
    char upper_alphabet[26];
    string str_upper_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int len = strlen(text);
    char new_text[len];
    char return_text[len];

    for (int i = 0; i < 26; i++)
    {
        decode[i] = toupper(key[i]);
        upper_alphabet[i] = str_upper_alphabet[i];
    }

    for (int i = 0; i < len; i++)
    {
        //caso seja uma letra
        if (isalpha(text[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                //buscando a letra no alfabeto maiusculo
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
        //caso n seja uma letra
        else
        {
            new_text[i] = text[i];
            //printf("%c\n",new_text[i]);
        }
    }
    strcpy(return_text, new_text);
    printf("%lu\n", strlen(return_text));
    printf("%lu\n", strlen(text));
//    printf("%lu\n", strlen(new_text));
    // printf("ciphertext: %s\n", return_text);
    printf("ciphertext: %s\n", return_text);

}