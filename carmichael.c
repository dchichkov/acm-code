#include <stdio.h>
unsigned short number;

int main()
{
    while (1)
    {
        scanf("%u", &number);

        if (number == 561 ||
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
            printf("The number %u is a Carmichael number.\n", number);
        else if (number != 0)
            printf("%u is normal.\n", number);
        else
            break;
    }

    return 0;
}
