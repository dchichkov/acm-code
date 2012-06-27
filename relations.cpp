#include <cstdio>

int main()
{
    long long a, b;
    int iterations = 0;
    scanf("%d", &iterations);
    while( --iterations >= 0 )
    {
        scanf("%lld %lld", &a, &b);
        (a > b) ? printf("%c", '>') : (a < b) ? printf("%c", '<') : printf("%c", '=');
        printf("\n");
    }
}
