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

typedef pair<double, double> point;
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)
#define EPS 1e-5

/*global variables*/
vp points;
/*global variables*/

struct srt
{
    bool operator()(const point& a, const point& b)
    {
        if (fabs(a.first-b.first) < EPS)
            return a.second < b.second;

        return a.first > b.first;
    }
};

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int np;
    scanf("%d ", &np);
    if (fabs(0 - np) < EPS) return false;
    double x, y;
    REP(i, np)
    {
        scanf("%lf %lf ", &x, &y);
        points.push_back(point(x, y));
    }
    return true;
}

void process()
{
    //process input
    sort(points.begin(), points.end(), srt());
    double min_dist = 10000.0;
    REP(i, (int)points.size()-1)
    {
            min_dist = min(min_dist, sqrt((points[i].first-points[i+1].first)*(points[i].first-points[i+1].first) +
                                          (points[i].second-points[i+1].second)*(points[i].second-points[i+1].second)));
    }

    if (fabs(10000.0-min_dist) < EPS) printf("INFINITY");
    else printf("%0.4lf", min_dist);
    puts("");
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        points.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
