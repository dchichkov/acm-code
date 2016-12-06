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
unsigned int a, b;
vi primes;
bitset<100000> bs;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    scanf("%u %u ", &a, &b);
    return true;
}

void process()
{
    //process input
    vi f1, f2;
    debug(a, endl);
    FOR(i, 2, a+1)
    {
        
        for (int j = 0; primes[j] < a+1 && i != 1; ++j)
        {
            while (i % primes[j] == 0)
            {
                f1.push_back(primes[j]);
                i /= primes[j];
                debug(i, TAB);
            }
        }
        debug(f1.size(), TAB);
        debug(f1.back(), endl);
    }
}

int main()
{
    bs.set();
    bs[0] = 0;
    bs[1] = 0;
    for (int i = 2; i <= 46341; ++i)
    {
        if (bs[i])
        {
            primes.push_back(i);
            for (int j = i*i; j <= 46341; j += i)
                bs.set(j, 0);
        }
    }
    debug(primes.size(), endl);
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
