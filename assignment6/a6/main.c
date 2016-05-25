/*
 * CS 261 Data Structures
 * Assignment 6
 * Name: Joseph DePrey
 * Date: 05/29/2016
 */ 
#include "hashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <assert.h>

/**
 * Allocates a string for the next word in the file and returns it. This string
 * is null terminated. Returns NULL after reaching the end of the file.
 * @param file
 * @return Allocated string or NULL.
 */
char* nextWord(FILE* file)
{
    int maxLength = 16;
    int length = 0;
    char* word = malloc(sizeof(char) * maxLength);
    while (1)
    {
        char c = fgetc(file);
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == '\'')
        {
            if (length + 1 >= maxLength)
            {
                maxLength *= 2;
                word = realloc(word, maxLength);
            }
            word[length] = c;
            length++;
        }
        else if (length > 0 || c == EOF)
        {
            break;
        }
    }
    if (length == 0)
    {
        free(word);
        return NULL;
    }
    word[length] = '\0';
    return word;
}

/**
 * Prints the concordance of the given file and performance information. Uses
 * the file input1.txt by default or a file name specified as a command line
 * argument.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char** argv)
{
    // FIXME: implement
    const char* fileName = "input1.txt";
    if (argc > 1)
    {
        fileName = argv[1];
    }
    printf("Opening file: %s\n", fileName);
    clock_t timer = clock();
    HashMap* map = hashMapNew(10);
    
    // --- Concordance code begins here ---
    // Be sure to free the word after you are done with it here.
    
    // Pointer to document
    FILE *file;
    
    file = fopen(fileName, "r");
    // Error message if unable to open file 
    if( file == NULL){
        fprintf( stderr, "Error opening %s\n\n", fileName );
        return 1;
    }
    char *word = nextWord(file);

    // Populate the concordance with words
    while(word){ 
        // If word is already in list then we increment count(value)
        if(hashMapContainsKey(map, word)){
            int * valuePtr = hashMapGet(map, word);
            assert(valuePtr != NULL);
            // Dereference value and increment
            (*valuePtr)++;
        }  else {
            // Word not found, so we add it to list with a starting count of 1
            hashMapPut(map, word, 1);
        }       
        free(word);
        word = nextWord(file);
    }
    // Print all words and occurrence counts
    for (int i = 0; i < map->capacity; i++){
        HashLink* link = map->table[i];
        if (link != NULL){
            printf("%s: %d\n", link->key, link->value);
            link = link->next;
        }
    }
    printf("\n");

    // Close file
    fclose(file);
    // --- Concordance code ends here ---
    
    hashMapPrint(map);
    
    timer = clock() - timer;
    printf("\nRan in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    printf("Empty buckets: %d\n", hashMapEmptyBuckets(map));
    printf("Number of links: %d\n", hashMapSize(map));
    printf("Number of buckets: %d\n", hashMapCapacity(map));
    printf("Table load: %f\n", hashMapTableLoad(map));
    
    hashMapDelete(map);
    return 0;
}