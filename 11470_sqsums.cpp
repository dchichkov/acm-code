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
    FOR(i, 0, n)
    {
        FOR(j, 0, n)
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
    int i = 0;
    int k = n-1;
    int ttl;
    while (i < k)
    {
        ttl = 0;
        FOR(j, i, k+1)
        {
            debug(nums[i][j], TAB);
            ttl += nums[i][j];
        }
        dbg (cout << endl; );
        FOR(j, i, k+1)
        {
            debug(nums[j][k], TAB);
            ttl += nums[j][k];
        }
        dbg (cout << endl; );
        FOR(j, i, k+1)
        {
            debug(nums[k][j], TAB);
            ttl += nums[k][j];
        }
        dbg (cout << endl; );
        FOR(j, i, k+1)
        {
            debug(nums[j][i], TAB);
            ttl += nums[j][i];
        }
        dbg (cout << endl; );
        ttl -= (nums[i][i] + nums[i][k] + nums[k][i] + nums[k][k]);
        printf(" %d", ttl);
        ++i;
        --k;
    }
    if (i == k)
        printf(" %d", nums[i][i]);
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
