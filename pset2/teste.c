#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char nome[1];
    nome[0] = 'S';
    string text = get_string("digita: ");

    printf("%s\n",nome);
    printf("%s\n",text);
    printf("%lu\n",strlen(text));
}