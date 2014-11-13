#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

//#define DEBUG  //comment this line to pull out print statements
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
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
const int MAX = 2000000;
int primes[MAX + 10];
vi sorted_list;
int n;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d ", &n);
    if (n == 0) return false;
    return true;
}

void process()
{
    //process input
    printf("%d\n", sorted_list[n-1]);
}

int main()
{
    //precompute
    REP(i, MAX+1)
        primes[i] = 1;
    primes[0] = 0;
    int mx = 0;
    FOR(i, 2, MAX+1)
    {
        if (primes[i] == 1)
        {
            for (int j = i+i, x; j <= MAX && j > 0; j += i)
            {
                x = j;
                while (x%i == 0)
                {
                    primes[j]++;
                    x /= i;
                }
                mx = max(mx, primes[j]);
            }
        }
    }

    debug(mx, endl);
    for (int i = 1; i <= mx; ++i)
    {
        for (int j = 1; j <= MAX; ++j)
        {
            if (primes[j] == i)
            {
                sorted_list.push_back(j);
            }
        }
    }


    debug(sorted_list.size(), endl);
    int casen = 1;
    while (getInput())
    {
        printf("Case %d: ", casen++);
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
