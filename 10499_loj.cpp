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
#define EPS 1E-9

/*global variables*/
long double n;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%llf ", &n);
    if (n < EPS) return false;
    return true;
}

void process()
{
    /*
      r = 1
      surface area of a sphere = 4*pi*r^2
      surface area of a slice of that sphere = pi * r^2
      do some algebra keeping in mind how many slices there are
      and also throw in some unneccesary precision.
    */
    //process input
    if (n == 1) n = 0;
    debug(n, TAB);
    //debug(n + 4, TAB); n = n+4;
    debug(n / 4.0, endl); n = n / 4.0;
    //debug(n - 1, TAB); n = n - 1;
    debug(n * 100, endl); n = n * 100;
    //n = (((((n) + 4) / 4.0) - 1) * 100);
    
    n = round(n);
    printf("%lld%%\n", (long long)n);
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
