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
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int n;
bool sieve[1000000];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    scanf("%d ", &n);
    return true;
}

void process()
{
    //process input
    int m;
    char rev[7];
    sprintf(rev, "%d", n);
    debug(rev, TAB);
    std::reverse(rev, rev+strlen(rev));
    debug(rev, TAB);
    sscanf(rev, "%d", &m);
    debug(n, TAB); debug(m, endl);
    printf("%d is %s.\n", n, (sieve[n] ? (sieve[m] && n != m ? "emirp" : "prime") : "not prime"));
}

int main()
{
    CL(sieve, 1);
    for ( int i = 2; i < 1000000; ++i)
    {
        if (sieve[i])
        {
            for (int j = i+i; j < 1000000; j += i)
                sieve[j] = 0;
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
