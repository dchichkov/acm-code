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


struct point
{
    double x, y;
    point() { x = y = 0; }
    point(int _x, int _y):x(_x),y(_y){}
};

typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)
#define EPS 1e-9
#define PI acos(-1.0)

/*global variables*/
point vertices[3];
vp points;
/*global variables*/

struct vec
{
    double x, y;
    vec(double _x, double _y):x(_x),y(_y){}
};

double norm_sq(vec v)
{
    return v.x * v.x + v.y * v.y;
}

double dot(vec a, vec b)
{
    return (a.x * b.x + a.y * b.y);
}

vec toVec(point a, point b)
{
    return vec(b.x - a.x, b.y - a.y);
}

double angle(point a, point o, point b)
{
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
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
    FOR(i, 1, sz-1)
    {
        if (ccw(P[i], P[i+1], P[(i+2) == sz ? 1 : i+2]) != isLeft)
            return false;
    }
    return true;
}

bool inPolygon(point pt, const vp& P)
{
    if ((int)P.size() == 0) return false;
    double sum = 0;
    for (int i = 0; i < (int)P.size()-1; ++i)
    {
        if (ccw(pt, P[i], P[i+1]))
            sum += angle(P[i], pt, P[i+1]);
        else sum -= angle(P[i], pt, P[i+1]);
    }
    return fabs(fabs(sum) - 2*PI) < EPS;
}

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%lf %lf %lf %lf %lf %lf ", &vertices[0].x, &vertices[0].y,
          &vertices[1].x, &vertices[1].y,
          &vertices[2].x, &vertices[2].y);

    if (vertices[0].x + vertices[0].y +
        vertices[1].x + vertices[1].y +
        vertices[2].x + vertices[2].y == 0)
        return false;

    vertices[0].x = max(vertices[0].x, 1.0);
    vertices[0].y = max(vertices[0].y, 1.0);
    vertices[1].x = max(vertices[1].x, 1.0);
    vertices[1].y = max(vertices[1].y, 1.0);
    vertices[2].x = max(vertices[2].x, 1.0);
    vertices[2].y = max(vertices[2].y, 1.0);
    vertices[0].x = min(vertices[0].x, 99.0);
    vertices[0].y = min(vertices[0].y, 99.0);
    vertices[1].x = min(vertices[1].x, 99.0);
    vertices[1].y = min(vertices[1].y, 99.0);
    vertices[2].x = min(vertices[2].x, 99.0);
    vertices[2].y = min(vertices[2].y, 99.0);
    points.push_back(vertices[0]);
    points.push_back(vertices[1]);
    points.push_back(vertices[2]);
    points.push_back(vertices[0]);
    return true;
}

void process()
{
    //process input
    point pt;
    int ttl = 0;
    FOR(i, 1, 100)
    {
        FOR(j, 1, 100)
        {
            pt.x = i;
            pt.y = j;
            if (inPolygon(pt, points))
                ttl++;
        }
    }
    printf("%d\n", ttl);
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
