// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <cs50.h>


#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = (LENGTH + 1) * 'z';

// Hash table
node *table[N];

int dictionarySize = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);
    node *cursor =table[index];
    while (cursor != NULL){
        if (strcasecmp(cursor->word,word)==0){
        return true;
        }
        else{
            cursor =cursor->next;
        }
    
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int sum=0;
    for(int i=0; strlen(word);i++){
        sum += tolower(word[i]);
    }
    return (sum % N);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file=fopen(dictionary,"r");
    if(file == NULL){
        printf("There is no dictionary %s\n",dictionary);
        //unload();
        return false;
    }
    
        
        char word[LENGTH + 1]; 
        
        
        while(fscanf(file,"%s",word) !=  EOF)
        {
        dictionarySize++;
        node *newnode =malloc(sizeof(node)); 
        if (newnode == NULL){
           
            return false;
        }
        
        strcpy(newnode->word,word);
        newnode->next = NULL;
        
        
        int index = hash(word);
        if(table[index]==NULL){
           table[index]=newnode;
        
    }
    else
    {
        newnode->next=table[index];
        table[index]=newnode;
   
    }
     
    
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dictionarySize;
    
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
     
   
    for (int i = 0; i < N; i++)
    {
        node *head = table[i];
        node *cursor = head;
        node *tmp = head;
        
        while (cursor != NULL)
        {
            
            cursor = cursor -> next;
            free(tmp);
            tmp = cursor;
        }
    }
    
    return true;
}
