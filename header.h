// Author: Fergus Haak
// Header file for Coursework 1.

#pragma once
#define MAX_LENGTH 100
#define DICT_LENGTH 40
#define LINE_LENGTH 1000

struct VarDict{
    char* key[DICT_LENGTH];
    int value[DICT_LENGTH];
};

void FillDictTemp(struct VarDict *dictionary, int dictLength);
void AddVariable(struct VarDict *dictionary,  char* varName, int dictLength);
void ReferenceVariable(struct VarDict *dictionary,  char* possibleVar, int dictLength);
void WriteDictToFile(struct VarDict *dictionary, int dictLength, char* fileName);