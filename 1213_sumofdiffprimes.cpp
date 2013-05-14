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
int n, k;
int precmp[1130][15];
vi primes;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d %d ", &n, &k);
    if (n == 0 && k == 0) return false;
    return true;
}

void sieve()
{
    int p[1121];
    memset(p, 1, sizeof(p));
    for (int i = 2; i < 1121; ++i)
    {
        if (p[i])
        {
            for (int j = i+i; j < 1121; j+=i)
                p[j] = 0;
        }
        primes.push_back(i);
    }
}

int pre_compute(int tot, int k_left, int pos)
{
    if (primes[pos] + tot == n)
        return 1;
    else if (primes[pos] + tot > n)
        return 0;
    return pre_compute(primes[pos+1]+tot, k_left-1, pos+1);
}

void process()
{
    //process input
}

int main()
{
    sieve();

    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
