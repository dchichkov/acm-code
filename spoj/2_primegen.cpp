#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <bitset>

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
bitset<100020> nms;
vi primes;
int x, y;
/*global variables*/

void sieve(int a, int b)
{   
    for (int i = a; i < b+1; ++i)
    {
        if (nms.test(i) == 0)
        {
            primes.push_back(i);
            for (int j = i+i; j < b+1; j+=i)
            {
                nms.set(j);
            }
        }
    }
}

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d %d ", &x, &y);
    return true;
}

void process()
{
    //process input
    bool prime;
    FOR(i, x, y+1)
    {
        prime = false;
        for (int j = 0; j < (int)primes.size() && primes[j] < y+1; ++j)
        {
            debug(primes[j], TAB); debug(i / primes[j], endl);
            if (i / primes[j] == 1 && i % primes[j] == 0)
            {
                prime = true;
                break;
            }   
        }
        debug(i, TAB); debug(prime, endl);
        if (prime) printf("%d\n", i);
    }
}

int main()
{
    int nc;
    scanf("%d ", &nc);
    primes.push_back(1);
    sieve(2, 100000);
    while (nc-- > 0)
    {
        getInput();
        process();
        if (nc != 0) puts("");
        /*CLEAR GLOBAL VARIABLES!*/
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
