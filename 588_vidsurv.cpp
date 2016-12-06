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

//typedef pair<int, int> point;
struct point
{
    int x, y;
    point() { x = y = 0; }
    point(int _x, int _y):x(_x),y(_y){}
};
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)
#define EPS 1e-9

/*global variables*/
vp points;
/*global variables*/

struct vec
{
    double x, y;
    vec(double _x, double _y):x(_x),y(_y){}
};

vec toVec(point a, point b)
{
    return vec(b.x - a.x, b.y - a.y);
}

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

bool ccw(point p, point q, point r)
{
    return cross(toVec(p, q), toVec(p, r)) >= 0;
}

bool collinear(point p, point q, point r)
{
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

bool isConvex(const vp& P)
{
    int sz = (int)P.size();
    if (sz <= 3) return false;
    bool isLeft = ccw(P[0], P[1], P[2]);
    //bool isColl = collinear(P[0], P[1], P[2]);
    FOR(i, 1, sz-1)
    {
        if (ccw(P[i], P[i+1], P[(i+2) == sz ? 1 : i+2]) != isLeft)// ||
            //      collinear(P[i], P[i+1], P[(i+2) == sz ? 1 : i+2]) != isColl)
            return false;
    }
    return true;
}


void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int N, a, b;
    scanf("%d ", &N);
    if (N == 0) return false;
    REP(i, N)
    {
        scanf("%d %d ", &a, &b);
        points.push_back(point(a, b));
    }
    points.push_back(points.front());
    return true;
}

void process()
{
    //process input
    printf("Surveillance is %s.\n", isConvex(points) ? "possible" : "impossible");
    puts("");
}

int main()
{
    int cn = 1;
    while (getInput())
    {

        printf("Floor #%d\n", cn++);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        points.clear();
        /*CLEAR GLOBAL VARIABLES!*/

    }

    return 0;
}
