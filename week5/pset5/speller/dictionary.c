// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

//Choose number of buckets in hash table
const unsigned int N = 65000;

// Hash table
node *table[N];
int dict_size = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // hash word with hash fxn
    int hash_value = hash(word);

    // look in linked list at hash_value index for word
    node *cursor = table[hash_value];

    // traverse looking for word
    while (cursor != NULL)
    {
//        if (strcasecmp(word, n->word) == 0)
        if (strcasecmp(cursor -> word, word) == 0)
        {
            return true;
        }
        cursor = cursor -> next;
    }
    return false;
}

// HASH function
unsigned int hash(const char *word)
{
    unsigned int result = 0;
    for (int i = 0; i < strlen(word); ++i)
    {
        result += tolower(word[i]) * 31;  //using prime 31
    }
    result = result % N;
    return result;
}

// LOADS dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // open dictionary file
    FILE *open_dictionary = fopen(dictionary, "r");

    // Check if null
    if (open_dictionary == NULL)
    {
        printf("Unable to open %s\n", dictionary);
        return false;
    }

    // read strings from file one at a time into word array
    char next_word[LENGTH + 1];
    while (fscanf(open_dictionary, "%s", next_word) != EOF)
    {
        // create new node for each word
        node *new_node = malloc(sizeof(node));
        // check if returns NULL
        if (new_node == NULL)
        {
            return false;
        }

        // use strcpy to copy word into node
        strcpy(new_node -> word, next_word);
        new_node -> next = NULL;

        // hash new_word via hash function
        int hash_value = hash(next_word);

        // insert node in hash table at hash_value location
        if (table[hash_value] == NULL)
        {
            table[hash_value] = new_node;
        }
        else
        {
            new_node -> next = table[hash_value];
            table[hash_value] = new_node;
        }
        dict_size++;
    }
    // close file
    fclose(open_dictionary);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{

    return dict_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    //iterate through hash table to free all nodes
    for (int i = 0; i < N; i++)
    {
        // assign a cursor for swapping
        node *cursor = table[i];

        // loop through linked lists in hash table
        // using a temp cursor (pointer)
        while (cursor != NULL)
        {
            node *temp = cursor; // temp = cursor

            cursor = cursor->next;  // cursor now points to next word

            free(temp);  // free temp, will be reset to cursor at top of loop
        }
        if (cursor == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
