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
vi dists;
bool first;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int a;
    scanf("%d ", &a);
    if (dists.empty() && a == -1)
        return false;
    else
    {
        if (!first)
            first = !first;
        else
            printf("\n");
    }

    while (a != -1)
    {
        dists.push_back(a*-1);
        scanf("%d ", &a);
    }
    return true;
}

void process()
{
    //process input
    int msf;
    vi LIS;
    LIS.push_back(1);
    FOR(i, 1, dists.size())
    {
        msf = 1;
        for (int j = i-1; j >= 0; --j)
            if (dists[j] <= dists[i]) msf = max(msf, LIS[j]+1);
        debug(msf, endl);
        LIS.push_back(msf);
    }
    REP(i, LIS.size())
        msf = max(msf, LIS[i]);
    printf("  maximum possible interceptions: %d\n", msf);
}

int main()
{
    int tc = 1;
    while (getInput())
    {
        printf("Test #%d:\n", tc++);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        dists.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
