#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

/*completed this program with the help of
 *the book : Competitive Programming 3
 *
 *pgs 271 - 279
*/

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

//typedef pair<int, int> point;

struct point {
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y):x(_x), y(_y){}
};

typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,(int)n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
const double PI = 3.141592653589793;
point a, b, c;
/*global variables*/

double area(double a, double b, double c)
{
    double semiperimeter = (a + b + c) / 2.0;
    //Heron's formula for area of triangle with 3 sides a, b, c
    //and semi-perimeter of triangle
    debug(semiperimeter, TAB);
    debug(sqrt(semiperimeter * (semiperimeter - a) * (semiperimeter - b) *
               (semiperimeter - c)), endl);
    return (sqrt(semiperimeter * (semiperimeter - a) * (semiperimeter - b) *
                 (semiperimeter - c)));
}

double dist(point p1, point p2)
{
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

double rCircumCircle(double ab, double bc, double ca)
{
    debug((ab * bc * ca) / (4.0 * area(ab, bc, ca)), endl);
    return (ab * bc * ca) / (4.0 * area(ab, bc, ca));
}

double rCircumCircle(point a, point b, point c)
{
    return rCircumCircle(dist(a, b), dist(b, c), dist(c, a));
}

void dump()
{
    //dump data
    debug(PI, endl);
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    scanf("%lf %lf %lf %lf %lf %lf ", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);
    return true;
}

void process()
{
    //process input
    printf("%0.2lf\n", (2 * PI * rCircumCircle(a, b, c)));
}

int main()
{
    dump();
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
