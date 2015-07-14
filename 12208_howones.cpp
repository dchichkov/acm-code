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
#define REP(i,n) FOR(i,0,(int)n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
#define LSOne(x) ((x)&(-x))
int a, b;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d %d ", &a, &b);
    if (!(a|b)) return false;
    return true;
}

void process()
{
    //process input
    int cnt = 0;
    int x;
    debug(a, TAB); debug(b, endl);
    FOR(i, a, b+1)
    {
        x = i;
        do
        {
            //debug(x, endl);
            if (x&1)
                cnt++;
        } while (x>>=1);
    }
    printf("%d\n", cnt);
}

int main()
{
    
    int cnt = 1;
    while (getInput())
    {
        printf("Case %d: ", cnt++);
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}