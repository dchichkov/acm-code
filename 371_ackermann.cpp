#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <limits>

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
int l, m, h, j;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d %d ", &l, &h);
    if (l == 0 && h == 0) return false;
    m = min(l, h);
    j = max(l, h);
    return true;
}

int length(unsigned int s)
{
    int ret = 0;
    do
    {
        if (s%2 == 0) s /= 2;
        else s = 3*s + 1;
        ret++;

    } while (s != 1);
    return ret;
}

void process()
{
    //process input    
    int mx = 0, c, len;
    FOR(i, m, j+1)
    {
        len = length(i);
        if (mx < len)
        {
            mx = len;
            c = i;
        }
        
    }
    printf("Between %d and %d, %lld generates the longest sequence of %lld values.\n",
           m, j, c, mx);
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
