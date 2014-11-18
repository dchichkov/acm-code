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
vector<double> prices;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int n;
    scanf("%d ", &n);
    if (n == 0) return false;
    double a;
    REP(i, n)
    {
        scanf("%lf ", &a);
        prices.push_back(a);
    }
    return true;
}

void process()
{
    //process input
    double ttl = 0.0;
    REP(i, (int)prices.size()-1)
    {
        ttl += fabs(prices[i]-prices[i+1]);
    }
    debug(ttl / (prices.size()-1), endl);
    //printf("$%0.2lf\n", ttl / (max((int)prices.size()-1, 1) * 1.0));
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        prices.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
