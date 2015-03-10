#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned short number;
char numbey[7];
char* normalness = " is normal.\n";
char* carmichaelness1 = "The number ";
char* carmichaelness2 = " is a Carmichael number.\n";

int main()
{
    while (1)
    {
        fgets(&numbey, 7, stdin);
        numbey[strlen(numbey)-1] = '\0';
        number = atoi(numbey);
        
        if (number == 561 || /* praying for a short-circuit */
            number == 1105 ||
            number == 1729 ||
            number == 2465 ||
            number == 2821 ||
            number == 6601 ||
            number == 8911 ||
            number == 10585 ||            
            number == 15841 ||
            number == 29341 ||
            number == 41041 ||
            number == 46657 ||
            number == 52633 ||
            number == 62745 ||
            number == 63973)
        {
            fputs(carmichaelness1, stdout);
            fputs(numbey, stdout);
            fputs(carmichaelness2, stdout);
        }
        else if (number != 0)
        {
            fputs(numbey, stdout);
            fputs(normalness, stdout);
        }
        else
            break;
    }

    return 0;
}
