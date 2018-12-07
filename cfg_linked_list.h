//
// Created by Krzysztof Piekarczyk on 2018-12-07.
//

#ifndef CFG_CFG_LINKED_LIST_H
#define CFG_CFG_LINKED_LIST_H

typedef struct _cfg_node {
    struct _cfg_node* next;
    char* token;
    char** substitutes;
    int num_of_substitutes;
} CFGNode;

void appendList(CFGNode **head_ref, char *token, char **substitutes, int n);
CFGNode* findByToken(CFGNode**, char*);
void destroyList(CFGNode**);

#endif //CFG_CFG_LINKED_LIST_H
