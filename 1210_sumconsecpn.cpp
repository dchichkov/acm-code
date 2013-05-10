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
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/

int num;
int prime[10001];
int precmp[10001];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d ", &num);
    if (num == 0) return false;
    return true;
}
/*

I WANT A LINEAR TIME SOLUTION!

 */

void sieve()
{
    for (int i = 2; i < 10001; ++i)
    {
        if (prime[i])
        {
            for (int j = i+i; j < 10001; j+=i, prime[j]=0);
        }
    }
}

void pre_comp()
{
    int t = 0;
    for (int i = 2; i < 10001; ++i)
    {
        t = 0;
        for (int j = i, k = i; j >= 2; --j)
        {
            if (prime[j])
            {
                k -= j;
                if (k < 0)
                {
                    k = i;
                    continue;
                }
                if (k == 0) t++;
            }
        }
    }
}

void process()
{
    printf("%d\n", precmp[num]);
}

int main()
{
    memset(prime, 1, sizeof(prime));
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
