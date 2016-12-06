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
int scores[100010];
int ns;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int a;
    scanf("%d ", &ns);
    REP(i, ns)
    {
        scanf("%d ", &a);
        scores[i] = a;
    }

    return true;
}

void process()
{
    //process input
    int mx, mxd;
    mxd = mx = numeric_limits<int>::min();
    REP(i, ns-1)
    {
        if (mx < scores[i])
            mx = scores[i];
        if (mxd < mx-scores[i+1])
            mxd = mx-scores[i+1];
    }
    printf("%d\n", mxd);
}

int main()
{
    int nc;
    scanf("%d ", &nc);
    //CL(scores, 0);
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        //CL(scores, 0);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
