#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <numeric>

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
#define REP(i,n) FOR(i,0,(int)n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
vi mbls;
int ttl1, ttl2;
/*global variables*/

void dump()
{
    //dump data
    REP(i, (int)mbls.size())
    {
        printf("%d ", mbls[i]);
    }
    puts("");
}

bool getInput()
{
    //get input
    int a;
    REP(i, 6)
    {
        scanf("%d ", &a);
        REP(j, a)
        {
            mbls.push_back(i+1);
        }
    }
    if (mbls.empty()) return false;
    return true;
}

void process()
{
    //process input
    SORT(mbls);
    dbg(dump(););
    int mx = accumulate(mbls.begin(), mbls.end(), 0) / 2;
    debug(mx, endl);
    REP(i, (int)mbls.size())
    {
        if (ttl1 < mx)
            ttl1 += mbls[i];
        else
            ttl2 += mbls[i];
        //debug(ttl1, TAB); debug(ttl2, endl);
    }
    printf("Can%s be divided.\n", ttl1 == ttl2 ? "" : "'t");
    puts("");
}

int main()
{
    int cnt = 1;
    while (getInput())
    {
        printf("Collection #%d:\n", cnt++);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        mbls.clear();
        ttl1 = ttl2 = 0;
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
