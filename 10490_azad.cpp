#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

#define DEBUG  //comment this line to pull out print statements
#ifdef DEBUG
#define TAB '\t'
#define debug(a, end) cout << #a << ": " << a << end
#define dbg(end) end
#else
#define debug(a, end)
#define dbg(end)
#endif

typedef pair<int, int> point;
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,(int)n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int n;
int isperf[32];
int isprime[32];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (scanf("%d ", &n) == EOF) return false;
    //if (n < 2 || n > 31) goto next;
    if (n == 0) return false;
    return true;
}

bool isperfect(long long p)
{
    long long num = pow(2, p-1) * (pow(2, p)-1);

    long long sum = 1;
    long long sqnum = (sqrt(num)+1);
    for (long long i = 2; i < sqnum; ++i)
    {
        if (num%i == 0)
        {
            sum += i;
            sum += num/i;
        }
    }
    return (num == sum);
}

void process()
{
    //process input
    long long num = pow(2, n-1) * (pow(2,n)-1);
    if (isperf[n])
        printf("Perfect: %lld!", num);
    else
    {
        if (isprime[n])
            printf("Given number is prime. But, NO perfect number is available.");
        else
            printf("Given number is NOT prime! NO perfect number is available.");
    }
    puts("");
}

int main()
{
    {
        isperf[2] = 1;
        isperf[3] = 1;
        isperf[5] = 1;
        isperf[7] = 1;
        isperf[13] = 1;
        isperf[17] = 1;
        isperf[19] = 1;
        isperf[31] = 1;
    }

    {
        isprime[2] = 1;
        isprime[3] = 1;
        isprime[5] = 1;
        isprime[7] = 1;
        isprime[11] = 1;
        isprime[13] = 1;
        isprime[17] = 1;
        isprime[19] = 1;
        isprime[23] = 1;
        isprime[29] = 1;
        isprime[31] = 1;
    }
    
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
