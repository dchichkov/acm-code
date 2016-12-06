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
#define REP(i,n) FOR(i,0,(int)n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int term;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (scanf("%d ", &term) == EOF) return false;
    return true;
}

void process()
{
    //process input
    int diag = 1;
    int b = 1;
    for (int i = 1; term > b; ++i, b += i, ++diag);

    b -= term;
    int num, denom;
    debug(b, endl);
    if (diag%2 != 0)
    {
        num = 1;
        denom = diag;
        REP(i, b)
        {
            num++;
            denom--;
        }
    }
    else
    {
        num = diag;
        denom = 1;
        REP(i, b)
        {
            num--;
            denom++;
        }
    }

    printf("TERM %d IS %d/%d\n", term, num, denom);
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
