#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <numeric>

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
            primes.push_back(i);
        }
    }
}

//ugh!
int pre_compute(int n, int k)
{
    int t = 0;
    vector<vector<int> > possibilities;
    bool placed;
    for (int i = 0; primes[i] <= n; ++i)
    {
        placed = false;
        REP(j, possibilities.size())
        {
            if (accumulate(possibilities[j].begin(), possibilities[j].end(), 0)+primes[i] <= n)
            {
                possibilities[j].push_back(primes[i]);
                placed = true;
            }
        }
        if (!placed)
        {
            vi new_set;
            new_set.push_back(primes[i]);
            possibilities.push_back(new_set);
        }
    }
    debug(possibilities.size(), endl);
    REP(i, possibilities.size())
    {
        debug(i, endl);
        REP(j, possibilities[i].size())
        {
            debug(j, TAB);
            debug(possibilities[i][j], TAB);
        }
    }
    dbg(cout << endl);
    REP(i, possibilities.size())
    {
        if (accumulate(possibilities[i].begin(), possibilities[i].end(), 0) == n
            && possibilities[i].size() == k)
            t++;
    }
    debug(t, endl);
    return t;
}

void process()
{
    //process input
    printf("%d\n", precmp[n][k]);
}

int main()
{
    sieve();

    for (int i = 1; i < 1121; ++i)
    {
        for (int j = 1; j < 15; ++j)
        {
            precmp[i][j] = pre_compute(i, j);
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
