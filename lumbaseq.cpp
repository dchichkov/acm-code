#include <cstdio>

using namespace std;

int main()
{
    int a[10];
    int num_cases;
    scanf("%d", &num_cases);
    bool ordered = false;
    printf("Lumberjacks:\n");
    while (num_cases-- > 0)
    {
        for (int i = 0; i < 10; ++i)
        {
            scanf("%d", &a[i]);
            //printf("%d ", a[i]);
        }
        //printf("\n");
        if (a[0] > a[1])
        {
            for (int i = 2; i < 10; ++i)
            {
                //printf("%d ", a[i]);
                if (a[i-1] < a[i]) break;
                else ordered = true;
                
            }
        }
        else if (a[0] < a[1])
        {
            for (int i = 2; i < 10; ++i)
            {
                //printf("%d ", a[i]);
                if (a[i-1] > a[i]) break;
                else ordered = true;
                
            }
        }
        
        (ordered) ? printf("Ordered\n") : printf("Unordered\n");
        ordered = false;
    }

    return 0;
}
