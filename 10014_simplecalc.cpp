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
int nci, az, al;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    double a, b;
    scanf("%d ", &nci);
    scanf("%lf ", &a);
    scanf("%lf ", &b);
    az = a*100;
    al = b*100;
    return true;
}

void process()
{
    //process input
    int ci;
    double cid;

    int ans;
    REP(i, nci)
    {
        scanf("%lf ", &cid);
        ci = cid*100;
        ans = (az + al)/2 - ci;
        al = az;
        az = ans;
    }

    printf("%0.2lf\n", (double)ans/100);
}

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
