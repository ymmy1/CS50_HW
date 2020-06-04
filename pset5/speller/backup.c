// Implements a dictionary's functionality
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Word count
int word_count = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int index = hash(word);
    node *cursor = table[index];
    if (cursor == NULL)
    {
        unload();
        return false;
    }
    while (true)
    {
        if (cursor == NULL)
        {
            break;
        }

        int result = strcasecmp(cursor->word, word);

        if (result == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int lower = tolower(word[0]);
    int i = lower - 97;

    return i;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *f = fopen(dictionary, "r");
    if (f == NULL)
    {
        printf("Could not open dictionary %s.\n", dictionary);
        unload();
        return 1;
    }


    char word[LENGTH + 1];
    while (true)
    {
        fscanf(f, "%s", word);

        if (feof(f))
        {
            break;
        }

        int index = hash(word);

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            unload();
            return false;
        }
        strcpy(n->word, word);
        n->next = table[index];

        table[index] = n;
        word_count++;
        // table[index]->next->word
    }

    // free(word);
    fclose(f);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (true)
        {

            if (cursor == NULL)
            {
                break;
            }
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        free(cursor);

    }
    return true;
}

// her.txt
// WORDS MISSPELLED:     767
// WORDS IN DICTIONARY:  143091
// WORDS IN TEXT:        18402
// TIME IN load:         0.02
// TIME IN check:        0.51
// TIME IN size:         0.00
// TIME IN unload:       0.00
// TIME IN TOTAL:        0.53

// vs cs50
// WORDS MISSPELLED:     767
// WORDS IN DICTIONARY:  143091
// WORDS IN TEXT:        18402
// TIME IN load:         0.03
// TIME IN check:        0.01
// TIME IN size:         0.00
// TIME IN unload:       0.01
// TIME IN TOTAL:        0.05