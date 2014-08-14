#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>

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
int jack, jill;
set<int> cds;
int total;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    total = 0;
    int a;
    scanf("%d %d ", &jack, &jill);
    if (!jack && !jill) return false;

    REP(i, jack)
    {
        scanf("%d ", &a);
        cds.insert(a);
    }

    REP(i, jill)
    {
        scanf("%d ", &a);
        if (cds.find(a) != cds.end()) total++;
    }
    return true;
}

void process()
{
    //process input
    printf("%d\n", total);
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        cds.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
