#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

/*#define DBG*/

#ifdef DBG
#define DEBUG if (TRUE)
#else
#define DEBUG if (FALSE)
#endif

#define CL(a, b) memset(a, b, sizeof(a));
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)
#define MAX(a, b) (((X)>(Y) ? (X) : (Y)))
/* GLOBALS */

/* END GLOBALS */

void dump()
{

}

int get_input()
{

    return TRUE;
}


void process()
{
    
}

int main(int args, char** argv)
{
    
    while (get_input())
    {
        process();

        /* CLEAR GLOBALS! */

        /* GLOBALS CLEARED! */
    }
    
    return 0;
}
