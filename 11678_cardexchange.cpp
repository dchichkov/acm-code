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
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int lena, lenb;
set<int> alice, betty, aerase;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int a;
    scanf("%d %d ", &lena, &lenb);

    if (!lena && !lenb) return false;
    REP(i, lena)
    {
        scanf("%d ", &a);
        alice.insert(a);
    }

    REP(i, lenb)
    {
        scanf("%d ", &a);
        if (alice.find(a) == alice.end())
        {
            betty.insert(a);
        }
        else
            aerase.insert(a);
    }

    for (set<int>::iterator it = aerase.begin(); it != aerase.end(); ++it)
    {
        debug(*it, endl);
        alice.erase(*it);
    }
    return true;
}

void process()
{
    //process input
    printf("%d\n", min((int)betty.size(), (int)alice.size()));
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        alice.clear();
        betty.clear();
        aerase.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
