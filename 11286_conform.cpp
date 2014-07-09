#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
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

/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int ns;
    set<int> ex;
    int mx = 0, a;
    map<set<int>, int> studs;
    scanf("%d ", &ns);
    if (ns == 0) return false;
    REP(i, ns)
    {
        REP(j, 5)
        {
            scanf("%d ", &a);
            ex.insert(a);
        }
        dbg (
            for (set<int>::iterator it = ex.begin(); it != ex.end(); ++it)
            {
                printf("%d ", *it);
            }
            puts("");
            );
        
        studs[ex] += 1;
        mx = max(mx, studs[ex]);
        ex.clear();
    }
    
    int total = 0;
    for (map<set<int>, int>::iterator it = studs.begin(); it != studs.end(); it++)
    {
        if (it->second == mx) total += it->second;
    }        
    
    printf("%d\n", total);
    
    return true;
}

void process()
{
    //process input
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
