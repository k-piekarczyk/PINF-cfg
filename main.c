#include <stdio.h>
#include "cfg_linked_list.h"

int main()
{
    CFGNode * tokenList = NULL;
    CFGNode * currentToken = NULL;
    char* token1 = "Tk";
    char* token2 = "Tk2";
    char* subs1[] = {"hel", "hit", "yo"};
    char* subs2[] = {"hel2", "hit3", "2", "nonyo"};

    appendList(&tokenList, token1, subs1, 3);
    appendList(&tokenList, token2, subs2, 4);

    currentToken = tokenList;
    while (currentToken != NULL)
    {
        printf("Token: %s\n", currentToken->token);

        printf("Substitutes: ");
        for (int i = 0; i < currentToken->num_of_substitutes; i++)
        {
            printf("%s", currentToken->substitutes[i]);
            if (i != currentToken->num_of_substitutes - 1)
                printf(", ");
        }
        printf("\n");
        currentToken = currentToken -> next;
    }
    CFGNode * nulltest = NULL;

    CFGNode * found = findByToken(&nulltest, "Tk3");
    if (found != NULL) printf("%s\n", found->substitutes[0]);
    else printf("Not found\n");

    destroyList(&tokenList);


    return 0;
}