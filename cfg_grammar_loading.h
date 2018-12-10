//
// Created by Krzysztof Piekarczyk on 2018-12-10.
//

#ifndef CFG_CFG_GRAMMAR_LOADING_H
#define CFG_CFG_GRAMMAR_LOADING_H

#include "cfg_linked_list.h"

void parseLine(const char*, CFGNode**);
CFGNode* loadGrammar(const char*);

#endif //CFG_CFG_GRAMMAR_LOADING_H
