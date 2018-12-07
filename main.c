#include <stdio.h>
#include "cfg_linked_list.h"

int main()
{
    CFGNode * tokenList = NULL;

    char* token = "Tk";
    char* subs[] = {"hel", "hit", ""};

    appendList(&tokenList, token, subs, 2);

    printf("Token: %s\n", tokenList->token);

    printf("Substitutes: ");
    for (int i = 0; i < tokenList->num_of_substitutes; i++)
    {
        printf("%s", tokenList->substitutes[i]);
        if (i != tokenList->num_of_substitutes - 1)
            printf(", ");
    }
    printf("\n");

    return 0;
}