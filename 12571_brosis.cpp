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
vector<unsigned int> ns;
unsigned int qs[231];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int n, q;
    scanf("%d %d ", &n, &q);
    unsigned int r;
    REP(i, n)
    {
        scanf("%d ", &r);
        ns.push_back(r);
    }
    REP(i, q)
    {
        scanf("%d ", &r);
        qs.push_back(r);
    }
    return true;
}

void process()
{
    //process input
    unsigned int maxz = 0;
    REP(i, qs.size())
    {
        debug(qs[i], TAB);
        REP(j, ns.size())
        {
            debug(ns[j], TAB);
            debug((ns[j]&qs[i]), endl);
            maxz = max((ns[j]&qs[i]), maxz);
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
        ns.clear();
        CL(qs, 0);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
