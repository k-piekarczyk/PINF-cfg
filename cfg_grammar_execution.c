//
// Created by Krzysztof Piekarczyk on 2018-12-10.
//

#include "cfg_grammar_execution.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* replaceToken(char* target, CFGNode* tokenNode)
{
    char* replacement = tokenNode->substitutes[rand() % tokenNode->num_of_substitutes];

    char* dest = malloc(strlen(target) - strlen(tokenNode->token) + strlen(replacement) + 1);
    char* ptr;

    strcpy(dest, target);

    ptr = strstr(dest, tokenNode->token);
    if (ptr)
    {
        memmove(ptr + strlen(replacement), ptr + strlen(tokenNode->token), strlen(ptr+strlen(tokenNode->token)) + 1);
        strncpy(ptr, replacement, strlen(replacement));
    }

    return dest;
}

char* expand(char* src, CFGNode** head_ref)
{
    CFGNode* currentNode = *head_ref;
    char* exp = malloc(strlen(src) + 1);
    strcpy(exp, src);

    while (currentNode != NULL)
    {
        exp = replaceToken(exp, currentNode);
        currentNode = currentNode->next;
    }

    if (strcmp(exp, src) == 0)
        return exp;
    return expand(exp, head_ref);
}