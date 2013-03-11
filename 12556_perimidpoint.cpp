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

typedef vector<int> vi; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
struct point
{
    double x;
    double y;
};
point triangle[3];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%lf %lf %lf %lf %lf %lf ", &triangle[0].x, &triangle[0].y,
          &triangle[1].x, &triangle[1].y, &triangle[2].x, &2[triangle].y);
    return true;
}

void process()
{
    //process input
    point D, E, F;
    double d, sd;
    double e, se;
    double f, sf;
    double IS = ~0x0;

    //distances
    f = sqrt(pow(triangle[2].x-triangle[0].x,2) + pow(triangle[2].y-triangle[0].y,2)); //dist C to A
    e = sqrt(pow(triangle[2].x-triangle[1].x,2) + pow(triangle[2].y-triangle[1].y,2)); //dist C to B
    d = sqrt(pow(triangle[1].x-triangle[0].x,2) + pow(triangle[1].y-triangle[0].y,2)); //dist B to A

    //slopes
    sf = (triangle[2].y-triangle[0].y) / (triangle[2].x-triangle[0].x); //A to C
    se = (triangle[2].y-triangle[1].y) / (triangle[2].x-triangle[1].x); //B to C
    sd = (triangle[1].y-triangle[0].y) / (triangle[1].x-triangle[0].x); //A to B

    D.y = sd*d;
    fabs(f - d - e);

    //E

    e2 = sqrt(pow(triangle[2].x-triangle[1].x,2) + pow(triangle[2].y-triangle[1].y,2)); //dist C to B
    E.y = triangle[0].y; //A's y coordinate
    E.x = triangle[0].x + fabs(d2 - d); //the difference from C to A and C to B

    //F
    f = sqrt(pow(triangle[2].x-triangle[0].x,2) + pow(triangle[2].y-triangle[0].y,2)); //dist C to A
    f2 = sqrt(pow(triangle[2].x-triangle[1].x,2) + pow(triangle[2].y-triangle[1].y,2)); //dist C to B
    F.y = triangle[0].y; //A's y coordinate
    F.x = triangle[0].x + fabs(d2 - d); //the difference from C to A and C to B
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

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
