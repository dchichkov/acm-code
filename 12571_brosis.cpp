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
unsigned int ns[100010];
unsigned int qs[30010];
int n, q;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d %d ", &n, &q);
    unsigned int r;
    REP(i, n)
    {
        scanf("%d ", &r);
        ns[i] = r;
    }
    REP(i, q)
    {
        scanf("%d ", &r);
        qs[i] = r;
    }
    return true;
}

void process()
{
    //process input
    int maxz = 0;
    sort(ns, ns+n);
    REP(i, q)
    {
        debug(qs[i], TAB);
        REP(j, n)
        {
            if ((qs[i]&ns[j]) != 0)
            {
                maxz = (qs[i]&ns[j]);
                break;
            }
        }
        dbg(cout << endl);
        printf("%d\n", maxz);
        maxz = 0;
    }
    
}

int main()
{
    int nc;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
