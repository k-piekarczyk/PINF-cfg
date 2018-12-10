#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cfg_linked_list.h"
#include "cfg_string_manipulation.h"

int main()
{
    CFGNode * tokenList = NULL;
    CFGNode * current = NULL;
    char* token1 = "Vb";
    char* token2 = "N";
    char* subs1[] = {"ide", "bic", "walczyc"};
    char* subs2[] = {"hel", "hit", "siedem", "krowa"};
    char* start = "Jestem Vb i N Vb";
    char* wynik;

    srand((unsigned int) time(0));

    appendList(&tokenList, token1, subs1, 3);
    appendList(&tokenList, token2, subs2, 4);

    wynik = expand(start, &tokenList);
    printf("Start: %s\n", start);
    printf("Wynik: %s\n", wynik);

    destroyList(&tokenList);

    return 0;
}