/* Class:   CSC 2700 Programming Competitions
 * Prof:    Isaac Traxler
 * Name:    Matthew Gavin
 * Problem: 10341 - Solve It
 *
 * CP2 book said bisection method. 
 */

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

const double PRECISION = 1e-9;

/*global variables*/
int p, q, r, s, t, u;

/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    scanf("%d %d %d %d %d %d ", &p, &q, &r, &s, &t, &u);
    debug(p, TAB);
    debug(q, TAB);
    debug(r, TAB);
    debug(s, TAB);
    debug(t, TAB);
    debug(u, endl);
    return true;
}

double f(double x)
{
    return p * exp(-x) +
            q * sin(x) +
            r * cos(x) +
            s * tan(x) +
            t * x * x +
            u;
}

void process()
{
    //process input
ad    double top = 1.0, bottom = 0.0;
    double x = (top+bottom)/2;

    double result;
    while (true)
    {
        result = f(x);
        //debug(top, TAB); debug(bottom, TAB); debug(x, TAB); debug(result, endl);
        if (abs(result) < PRECISION) break;
        else if ( result < 0 )
        {
            top = x-PRECISION;
            x = (top+bottom) / 2;
            
            if (x < 0) break;
        }
        else if (result > 0)
        {
            bottom = x+PRECISION;
            x = (bottom+top) / 2;

            if (x > 1) break;
        }
    };
    debug(f(0), TAB); debug(f(1), endl);
    if (f(0) == 0) x = 0;        //thank you UVA forums
    else if (f(1) == 0) x = 1;   //       ^
    if (x < 0 || x > 1) printf("No solution");
    else printf("%0.4lf", x);

    printf("\n");

    debug(top, TAB); debug(bottom, TAB); debug(x, TAB); debug(result, endl);
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
