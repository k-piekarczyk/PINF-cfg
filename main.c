#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cfg_linked_list.h"
#include "cfg_grammar_execution.h"
#include "cfg_grammar_loading.h"

int main()
{
    srand((unsigned int) time(0));
    CFGNode * tokenList = NULL;
    char* start = "S";
    char* wynik;

    tokenList = loadGrammar("demo.grammar");

    wynik = expand(start, &tokenList);
    printf("Start: %s\n", start);
    printf("Wynik: %s\n", wynik);

    destroyList(&tokenList);
    return 0;
}