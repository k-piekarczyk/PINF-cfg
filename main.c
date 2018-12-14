#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "cfg_linked_list.h"
#include "cfg_grammar_execution.h"
#include "cfg_grammar_loading.h"

int main(int argc, char** argv)
{   
    if (argc < 2)
    {
        printf("Too little arguments. Usage: %s fileName (opt)[sentenceToExpand]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    srand((unsigned int) time(0));
    CFGNode * tokenList = NULL;
    char* fileName = argv[1];
    char* start = argc > 2 ? argv[2] : "S.";
    char* wynik;


    tokenList = loadGrammar(fileName);

    if(tokenList == NULL)
    {
        printf("File '%s' is empty.\n", fileName);
        exit(EXIT_FAILURE);
    }

    wynik = expand(start, &tokenList);
    printf("Start: %s\n", start);
    printf("Wynik: %s\n", wynik);

    destroyList(&tokenList);
    exit(EXIT_SUCCESS);
}