#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <bitset>

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
const int MAX = 1E6;
bitset<MAX> primes;
int n;
/*global variables*/

void dump()
{
    //dump data
}

bool ispp(int num)
{
    char pal[20];
    sprintf(pal, "%d", num);
    for (int i = 0; i < (strlen(pal)+1)/2; ++i)
    {
        if (pal[i] != pal[strlen(pal)-i-1])
            return false;
    }
    return primes[num];
}

bool getInput()
{
    //get input
    scanf("%d ", &n);
    return true;
}

bool process()
{
    //process input
    long long t = n*2;
    printf("%lld\n", t);
    if (ispp(n)) return false;
    return true;
}

int main()
{
    primes.set();
    //sieve
    FOR(i, 2, sqrt(MAX))
    {
        if (primes[i])
        {
            for (int j = i*i; j < MAX; j += i)
            {
                primes[j] = 0;
            }
        }
    }
    
    while (getInput())
    {

        if (!process())
            break;

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
