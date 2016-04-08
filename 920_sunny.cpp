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
vp landscape;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int np;
    scanf("%d ", &np);
    point a;
    REP(i, np)
    {
        scanf("%d %d ", &a.first, &a.second);
        landscape.push_back(a);
    }

    return true;
}

void process()
{
    //process input
    sort(landscape.begin(), landscape.end(), [](const point& a, const point& b)
         {
             if (a.first == b.first)
                 return a.second > b.second;
             else
                 return a.first > b.first;
         });
    vp visible;
    int peak = -1;
    REP(i, landscape.size())
    {
        if (landscape[i].second > peak)
        {
            visible.push_back(landscape[i]);
            peak = landscape[i].second;
        }
    }
    dbg (
        REP(i, visible.size())
        {
            debug(visible[i].first, TAB); debug(visible[i].second, endl);
        }
        );

    vector<double> calculations;
    double xdelta, ydelta, xbelow, ybelow;
    double slope, b;
    double tot;
    //first calculation, a^2 + b^2 = c^2
    ydelta = visible[1].second - visible[0].second;
    xdelta = visible[0].first - visible[1].first;
    calculations.push_back(sqrt(pow(xdelta,2) + pow(ydelta,2)));
    debug(calculations[0], endl);
    //now y=mx+b (slope intercept form) for the rest of the points
    vp::iterator it;
    FOR(i, 1, visible.size()-1)
    {
        it = find(landscape.begin(), landscape.end(), visible[i+1]);
        (--it);
        ybelow = it->second;
        xbelow = it->first;
        //slope = yabove-ybelow/xabove-xbelow
        slope = (visible[i+1].second-ybelow) / (visible[i+1].first-xbelow);
        b = visible[i+1].second - (slope*visible[i+1].first);
        xdelta = (visible[i].second - b) / slope; //find the point where the top point of the
                                                  //previous mountain
                                                  //meets the angled line of the mountain
        debug(slope, TAB); debug(b, TAB);
        xdelta -= visible[i+1].first; //subtract furthest left x
        ydelta = visible[i+1].second - visible[i].second;
        debug(xdelta, TAB); debug(ydelta, endl);
        //now find hypotenuse
        calculations.push_back(sqrt(pow(xdelta,2) + pow(ydelta,2)));
        dbg (
        tot = accumulate(calculations.begin(), calculations.end(), 0.0);
        debug(tot, endl);
            );
    }
    tot = accumulate(calculations.begin(), calculations.end(), 0.0);
    printf("%0.2lf\n", tot);    
}

int main()
{
    int nc;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        landscape.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
