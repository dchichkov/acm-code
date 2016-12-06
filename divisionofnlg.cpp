#include <cstdio>
#include <iostream>

using namespace std;

#define DEBUG
//#undef DEBUG //uncomment this line to pull out print statements
#ifdef DEBUG
#define TAB '\t'
#define debug(a, end) cout << #a << ": " << a << end
#else
#define debug(a, end)
#endif

int main()
{
    int n,m,k, c1, c2;
    scanf("%d", &k);
    while (k != 0)
    {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < k; ++i)
        {
            //check on dividing line
            scanf("%d %d", &c1, &c2);
            if (c1 == n || c2 == m)
            {
                printf("divisa\n");
                continue;
            }
            //check y
            if (c2 < m)
                printf("S");
            else
                printf("N");
            //check x
            if (c1 > n)
                printf("E\n");
            else printf("O\n");
        }
        
        scanf("%d", &k);
    }

    return 0;
}
