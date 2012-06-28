#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define DEBUG
#undef DEBUG //uncomment this line to pull out print statements
#ifdef DEBUG
#define TAB '\t'
#define debug(a, end) cout << #a << ": " << a << end
#else
#define debug(a, end)
#endif

int main()
{
    char num[11];
    int ans = 10;
    scanf("%s", num);
    while (strcmp(num, "0") != 0)
    {
        debug(num, endl);
        while (ans >= 10)
        {
            ans = 0;
            for (int i = 0; i < strlen(num); ++i)
            {
                ans += num[i] - '0';
            }
            sprintf(num, "%i", ans); //write ans to num
        }
        printf("%i\n", ans);
        ans = 10;
        scanf("%s", num);
        
    }
}
