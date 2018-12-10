#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cfg_linked_list.h"
#include "cfg_grammar_execution.h"
#include "cfg_grammar_loading.h"

int main()
{
    CFGNode * tokenList = NULL;
    CFGNode * current = NULL;
    char* token2 = "N";
    char* subs2[] = {"hel", "hit", "siedem", "krowa"};
    char* start = "Jestem Vb i N Vb";
    char* wynik;

    srand((unsigned int) time(0));

    parseLine("Vb>stuff|walka|other stuff|damn,|how did it get here?", &tokenList);
    appendList(&tokenList, token2, subs2, 4);

    wynik = expand(start, &tokenList);
    printf("Start: %s\n", start);
    printf("Wynik: %s\n", wynik);

    destroyList(&tokenList);

    return 0;
}