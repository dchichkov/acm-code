#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
//#include <cmath>
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
#define REP(i,n) FOR(i,0,(int)n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
static int x1, y1, x2, y2;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d %d %d %d ", &x1, &y1, &x2, &y2);
    if (x1 == 0) return false;
    return true;
}

void process()
{
    //process input
    if (x1 == x2 && y1 == y2)
        puts("0");
    else if (abs(x1-x2) == abs(y1-y2) || (y1-y2 == 0) || (x1-x2 == 0))
        puts("1");
    else if (x2 != x1 && y2 != y1)
        puts("2");
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
