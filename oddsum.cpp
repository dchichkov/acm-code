#include <cstdio>

using namespace std;

int main()
{
    int a, b, t;
    scanf("%d", &t);
    int sum;
    int count = 0;
    
    while (t-- > 0)
    {
        scanf("%d\n %d", &a, &b);
        sum = 0;
        for (int i = ((a%2) ? a : a+1); i <= ((b%2) ? b : b-1); i+=2)
            sum += i;

        printf("Case %d: %d\n", ++count, sum);
    }

    return 0;
}
