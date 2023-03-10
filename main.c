// Author: Fergus Haak
// Date of last modification: 09/03/2023
// Main file for Coursework 1.

#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char **argv) {

    // create array which can hold var name and uses
    struct VarDict varDictArray[DICT_LENGTH];
    FillDictTemp(varDictArray, DICT_LENGTH);
    // takes the file name as the first argument when program is run
    char *fileName = argv[1];

    // declare delimiters and search terms
    char *delims = " \n\t";
    char *commentPrefix = "//";
    char *variableDeclarators[3] = {"int", "char", "double"};

    // declare console output variables
    int lineCount = 0;
    int characterCount = 0;
    int commentCount = 0;
    int variableCount = 0;

    // open source file
    FILE *input_file = fopen(fileName, "r");

    // iterate through source file line by line
    char line[LINE_LENGTH];
    while(fgets(line, LINE_LENGTH, input_file) != NULL)
    {
        lineCount++;

        // this variable is used to find out if the line the word is from is a comment or not
        int isComment = 0;

        // split by word
        char* token = strtok(line, delims); // split string on spaces
        while(token != NULL)
        {
            // increase character count by length of word
            characterCount += strlen(token);
            ReferenceVariable(varDictArray, token, DICT_LENGTH);

            // checks to see if line is a comment
            if(strcmp(token, commentPrefix) == 0)
            {
                commentCount++;
                isComment = 1;
            }

            // only runs if line != comment
            if (isComment == 0){
                // perform variable test 3 times for each possible declarator
                for(int i=0; i<= 2; i++){
                    if(strcmp(token, variableDeclarators[i]) == 0)
                    {
                        // when a similar token is found use a temp token to look two words ahead for a '('
                        char* tempToken = token;

                        // skips the next two words but counts their characters
                        token = strtok(NULL, delims);
                        char* varName = token;
                        characterCount += strlen(token);
                        token = strtok(NULL, delims);
                        characterCount += strlen(token);


                        // test if second word after the variable declarator is '('
                        if (strcmp(token, "(") != 0){
                            variableCount++;
                            AddVariable(varDictArray, varName, DICT_LENGTH);
                        }

                        token = tempToken;

                    }
                }
            }

            // continues on to the next word seperated by a space
            token = strtok(NULL, delims);
        }
    }

    // console output
    printf("Total number of lines: %d\n", lineCount);
    printf("Number of characters: %d\n", characterCount);
    printf("Number of comments: %d\n", commentCount);
    printf("Total number of variables: %d", variableCount);

    WriteDictToFile(varDictArray, DICT_LENGTH, argv[1]);

    // close source file
    fclose(input_file);
    return 0;
}


void FillDictTemp(struct VarDict *dictionary, int dictLength){
    for (int i = 0; i < dictLength; i++) {
        dictionary->key[i] = "temp";
        dictionary->value[i] = 0;
    }
}


void AddVariable(struct VarDict *dictionary,  char* varName, int dictLength) {
    for (int i = 0; i < dictLength; i++) {
        if (strcmp(dictionary->key[i], "temp") == 0) {
            dictionary->key[i] = malloc(strlen(varName) + 1); // +1 for null terminator
            strcpy(dictionary->key[i], varName);
            return;
        }
    }
    printf("Dictionary is full!\n");
}

void ReferenceVariable(struct VarDict *dictionary,  char* possibleVar, int dictLength){
    for (int i = 0; i < dictLength; i++) {
        if(strcmp(dictionary->key[i], possibleVar) == 0){
            // variable found in dictionary
            dictionary->value[i]++;
        }
    }
}


void WriteDictToFile(struct VarDict *dictionary, int dictLength, char* fileName){
    FILE *outputFile;
    // create output file name from input file name
    fileName[strlen(fileName) - 2] = '\0';
    strcat(fileName, ".s");

    // open file for writing
    outputFile = fopen(fileName, "w");

    // check for errors opening
    if (outputFile == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < dictLength; i++) {
        if (strcmp(dictionary->key[i], "temp") != 0){
            fprintf(outputFile, "%s\t%d\n", dictionary->key[i], dictionary->value[i]);
        }
    }

    fclose(outputFile);  // close file
}