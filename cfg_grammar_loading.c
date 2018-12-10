//
// Created by Krzysztof Piekarczyk on 2018-12-10.
//

#include "cfg_grammar_loading.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUB_BUFFER 256
#define LINE_BUFFER 256

void parseLine(const char* src, CFGNode** head_ref)
{
    char* bufor[SUB_BUFFER];
    char* line = malloc(strlen(src) + 1);
    strcpy(line, src);
    int cnt = 0;
    char** substitutes;
    char* token;

    char* ptr = strtok(line, ">");
    token = ptr;

    while (ptr != NULL)
    {
        ptr = strtok(NULL, "|");
        if (ptr != NULL)
        {
            bufor[cnt] = ptr;
            cnt++;
        }
    }

    substitutes = malloc(cnt * sizeof(char*));
    for (int i = 0; i < cnt; i++)
    {
        substitutes[i] = bufor[i];
    }

    appendList(head_ref, token, substitutes, cnt);
}

CFGNode* loadGrammar(const char* fileName)
{
    FILE * fp;
    char line[LINE_BUFFER];
    CFGNode* grammarList = NULL;

    fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        printf("No file.\n");
        return NULL;
    }

    while (fgets(line, sizeof line, fp) != NULL)
    {
        strtok(line, "\n");
        parseLine(line, &grammarList);
    }
    fclose(fp);
    return grammarList;
}