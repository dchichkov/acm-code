#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

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
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int n;
int nums[12][12];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d ", &n);
    if (n == 0) return false;
    FOR(i, 1, n+1)
    {
        FOR(j, 1, n+1)
        {
            scanf("%d ", &nums[i][j]);
        }
    }
    return true;
}

void process()
{
    //process input
    //add up all sides
    int rc, fin = (ceil(n*1.0/2))+1;
    rc = 1;
    int ttl;
    while (rc != fin)
    {
        ttl = 0;
        FOR(i, 1, n-rc+2)
        {
            ttl += nums[n-rc+1][i];
            debug(n-rc+1, TAB); debug(i, TAB);
            debug(nums[n-rc+1][i], endl);
        }
        dbg(puts(""););
        FOR(i, 1, n-rc+2)
        {
            ttl += nums[i][n-rc+1];
            debug(i, TAB); debug(n-rc+1, TAB);
            debug(nums[i][n-rc+1], endl);
        }
        dbg(puts(""););
        FOR(i, 1, n-rc+2)
        {
            ttl += nums[rc][i];
            debug(rc, TAB); debug(i, TAB);
            debug(nums[rc][i], endl);
        }
        dbg(puts(""););
        FOR(i, 1, n-rc+2)
        {
            ttl += nums[i][rc];
            debug(i, TAB); debug(rc, TAB);
            debug(nums[i][rc], endl);
        }
        dbg(puts(""););
        printf(" %d", ttl);
        rc++;
    }
    puts("");
}

int main()
{
    int csn = 1;
    while (getInput())
    {

        printf("Case %d:", csn++);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        CL2d(nums, 0, 11, 11);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
