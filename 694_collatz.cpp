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
long long i, j;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%lld %lld ", &i, &j);
    if (i < 0 && j < 0) return false;
    return true;
}

void process()
{
    //process input
    int c = 0;
    long long t;
    for (t = min(i,j); t <= max(i, j) && t != 1;)
    {
        debug(t, endl);
        if (t%2)
            t = 3*t+1;
        else
            t /= 2;
        c++;
    }
    if (t == 1) ++c;
    printf("A = %lld, limit = %lld, number of terms = %d\n", i, j, c);
}

int main()
{
    int count = 0;
    while (getInput())
    {
        printf("Case %d: ", ++count);
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
