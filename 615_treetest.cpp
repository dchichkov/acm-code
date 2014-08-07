#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>

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

bool hasacycle;
set<int> children;
set<int> parents;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int a,b;
    pair<set<int>::iterator, bool> rt;
    while (scanf("%d %d ", &a, &b), (a != 0 || b != 0))
    {
        if (a == -1 && b == -1) return false;
        rt = children.insert(b);
        parents.insert(a);
        debug(a, TAB); debug(b, TAB); debug(rt.second, endl);
        if (rt.second == false || a == b)
            hasacycle = true;
    }
           
    return true;
}

void process()
{
    //process input
    int np = 0;
    for (set<int>::iterator it = parents.begin(); it != parents.end(); ++it)
        if (children.find(*it) == children.end()) np++;
    debug(np, TAB);
    debug(hasacycle, TAB); debug(parents.size(), TAB); debug(children.size(), endl);
    printf("is%s a tree.\n", (hasacycle || np > 1) ? " not" : "");
}

int main()
{
    int cn = 0;
    while (getInput())
    {
        printf("Case %d ", ++cn);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        hasacycle = false;
        children.clear();
        parents.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
