#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cfg_linked_list.h"
#include "cfg_grammar_execution.h"
#include "cfg_grammar_loading.h"

int main()
{
    CFGNode * tokenList = NULL;
    char* start = "Jestem Vb i N Vb";
    char* wynik;

    srand((unsigned int) time(0));
    tokenList = loadGrammar("test.grammar");

    wynik = expand(start, &tokenList);
    printf("Start: %s\n", start);
    printf("Wynik: %s\n", wynik);

    destroyList(&tokenList);

    return 0;
}