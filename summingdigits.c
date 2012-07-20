#include <stdio.h>

int main()
{
    int ans = 0;
    scanf("%d", &ans);
    while (ans != 0)
    {
        ans %= 9;
        printf("%d\n", (ans == 0) ? 9 : ans);
        scanf("%d", &ans);   
    }

    return 0;
}
