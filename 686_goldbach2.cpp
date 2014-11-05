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
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
#define MAX_S 32999
int n;
bitset<MAX_S> sieve;
vi primes;
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
    int cnt = 0;
    for (int i = 0; primes[i] < n; ++i)
        for (int j = 0; j <= i; ++j)
            if (primes[i] + primes[j] == n)
                ++cnt;

    printf("%d\n", cnt);
}

int main()
{
    //precompute
    sieve[0] = 1;
    sieve[1] = 1;
    FOR(i, 2, MAX_S)
    {
        if (sieve[i] == 0)
        {
            primes.push_back(i);
            for (int j = i*i; 2 < j && j <= MAX_S; j += i)
            {
                sieve[j] = 1;
            }
        }
    }
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
