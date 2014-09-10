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
int f, s;
int nums[10];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    scanf("%d %d ", &f, &s);
    return true;
}

void process()
{
    //process input

    char a[10];
    bool cd;
    int cnt = 0;
    FOR(i, f, s+1)
    {
        cd = true;
        CL(nums, 0);
        sprintf(a, "%d", i);
        REP(i, strlen(a))
        {
            debug((int)a[i]-0x30, TAB); debug(nums[((int)a[i]-0x30)], endl);
            if (nums[((int)a[i]-0x30)])
            {
                cd = false;
                break;
            }
            nums[((int)a[i]-0x30)]++;
        }
        if (cd) ++cnt;
    }
    printf("%d\n", cnt);
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
