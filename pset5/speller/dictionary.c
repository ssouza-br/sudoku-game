// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

int word_number;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    //node *cursor = table[hash(word)]->next;
    //printf("hash: %i, word: %s\n", hash(word), word);
    for (node *tmp =  table[hash(word)]; tmp != NULL; tmp=tmp->next)
    {
        if (strcasecmp(tmp->word, word) == 0)
        {
            //printf("encontrei palavra\n");
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary,"r");
    //printf("eu entrei aqui\n");
    if (file == NULL)
        {
            //printf("bug no arqui\n");
            return false;
        }
    char word_read[LENGTH + 1];
    word_number = 0;

    while (fscanf(file,"%s", word_read) != EOF)
    {
        //printf("estou no fscanf. word number: %i. word: %s\n", word_number, word_read);
        node *n = malloc(sizeof(node));
        n->next = NULL;
        if (n == NULL)
        {
            return false;
        }
        word_number++;
        //printf("words in dict: %i\n", word_number);
        strcpy(n->word, word_read);

        //printf(" foo: %s\n", n->word);
        //n = table[hash(word_read)];
        if (table[hash(word_read)] != NULL)
        {
            //printf("hash: %i word_read: %s\n",hash(word_read), word_read);
            //printf("next word after buck: %s next next word after buck: %s\n", table[hash(word_read)]->next->word, table[hash(word_read)]->next->next->word);
            // //printf("word: %s\n",n->next->word);
            n->next = table[hash(word_read)]->next;
            table[hash(word_read)]->next = n;
        }
        else
        {
            //printf("hash: %i word_read: %s\n",hash(word_read), word_read);
            table[hash(word_read)] = n;
        }
        //table[hash(word_read)] = n;
    }
    // for (node *tmp =  table[0]; tmp != NULL; tmp=tmp->next)
    // {
    //     printf("%s\n", tmp->word);
    // }
    //free(n);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // if (unload())
    // {
    //     return 0;
    // }
    //printf("words in dict: %i\n", word_number);
    return word_number;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *tmp = table[i]->next;
            free(table[i]);
            table[i] = tmp;
        }
    }
    return true;
}
