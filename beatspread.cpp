#include <cstdio>
#include <algorithm>

using namespace std;

int get_b(int sum, int diff)
{
    return (sum-diff)/2;
}

int main()
{
    int num_scores = 0;
    int sum, diff, a, b;
    scanf("%d", &num_scores);
    while (num_scores-- > 0)
    {
        scanf("%d %d", &sum, &diff);
        b = get_b(sum, diff);
        a = sum - b;
        /*output*/
        if (diff > sum || (min(a,b) < 0) || a+b != sum || max(a,b) - min(a,b) != diff)
        {
            printf("impossible\n");
        }
        else
        {
            printf("%d %d\n", max(a,b), min(a,b));
        }
        /*output*/
    }

    return 0;
}
