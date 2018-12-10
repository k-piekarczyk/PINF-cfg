//
// Created by Krzysztof Piekarczyk on 2018-12-10.
//

#include "cfg_grammar_loading.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parseLine(const char* src, CFGNode** head_ref)
{
    char* bufor[255];
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