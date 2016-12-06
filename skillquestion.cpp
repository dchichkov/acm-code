#include <cstdio>
#include <iostream>
#include <cmath>

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
    int amt_to_do;
    int c;
    scanf("%d", &amt_to_do);
    while (amt_to_do-- > 0)
    {
        scanf("%d", &c);
        c = 315*c+36962;
        printf("%d\n", (int)abs(c%100/10));
    }
}
