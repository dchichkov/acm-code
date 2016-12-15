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

/*global variables*/
long double sa, sb, sc;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (scanf("%llf %llf %llf ", &sa, &sb, &sc) == EOF) return false;
    return true;
}

void process()
{
    //process input

    //heron's formula
    debug(sa, TAB); debug(sb, TAB); debug(sc, endl);
    long double sp = (sa + sb + sc) / 2.0; //semi-perimeter
    debug(sp, endl);
    long double area = sqrt(sp*(sp-sa)*(sp-sb)*(sp-sc)); //formula
    debug(area, endl);
    //end 

    
    long double radius = area / sp; //huh.
    if (sa == 0 || sb == 0 || sc == 0) radius = 0;
    printf("The radius of the round table is: %0.3llf\n", round(radius*1000)/1000);
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
