//
// Created by Krzysztof Piekarczyk on 2018-12-07.
//

#include <stdlib.h>
#include <string.h>
#include "cfg_linked_list.h"

void appendList(CFGNode **head_ref, char *token, char **substitutes, int n)
{
    CFGNode* new_node = (CFGNode *) malloc(sizeof(CFGNode));
    CFGNode* current = *head_ref;

    new_node->next = NULL;
    new_node->token = token;
    new_node->substitutes = substitutes;
    new_node->num_of_substitutes = n;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (current->next != NULL)
        current = current->next;

    current->next = new_node;
}

CFGNode* findByToken(CFGNode** head_ref, char* token)
{
    CFGNode* current = *head_ref;

    while (current != NULL)
    {
        if (strcmp(current->token, token) == 0) return current;
        current = current->next;
    }

    return NULL;
}

void destroyList(CFGNode** head_ref)
{
    CFGNode* current = *head_ref;
    CFGNode* next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    *head_ref = NULL;
}