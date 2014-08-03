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
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int h, u, d, f;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d %d %d %d ", &h, &u, &d, &f);
    if (!(int)h) return false;
    return true;
}

void process()
{
    //process input
    h *= 100;
    u *= 100;
    d *= 100;
    double fatigue = (u * (f*0.01));
    debug(fatigue, TAB);
    double climbed = 0;
    int days = 0;
    while (climbed < h)
    {
        days++;
        debug(climbed, TAB); debug(u, TAB); debug(days, endl);
        climbed += u;
        u -= fatigue;
        u = max(u, 0);
        if (climbed > h) break;
        climbed -= d;
        if (climbed < 0) break;
    }

    printf("%s on day %d\n", (climbed-h) > 0 ? "success" : "failure", days);
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
