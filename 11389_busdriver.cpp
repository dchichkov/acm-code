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
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int n;
int d;
int r;
vi drivers, mroutes, nroutes;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d %d %d ", &n, &d, &r);
    if (n == 0 && d == 0 && r == 0)
        return false;
    return true;
}

void process()
{
    //process input
    int mroute, nroute;
    unsigned long long total = 0;
    REP(i, n)
    {
        scanf("%d ", &mroute);
        mroutes.push_back(mroute);
    }
    REP(i, n)
    {
        scanf("%d ", &nroute);
        nroutes.push_back(nroute);
    }

    sort(mroutes.begin(), mroutes.end());
    sort(nroutes.begin(), nroutes.end());
    reverse(nroutes.begin(), nroutes.end());
    drivers.resize(n);
    REP(i, n)
    {
        drivers[i] = mroutes[i] + nroutes[i];
    }

    REP(i, n)
    {
        total += max((drivers[i] - d), 0) * r;
    }
    printf("%d\n", total);
    
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        drivers.clear();
        mroutes.clear();
        nroutes.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
