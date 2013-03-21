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
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
point vertices[3];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%lf %lf %lf %lf %lf %lf ", &vertices[0].first, &vertices[0].second,
          &vertices[1].first, &vertices[1].second,
          &vertices[2].first, &vertices[2].second);

    if (vertices[0].first + vertices[0].second +
        vertices[1].first + vertices[1].second +
        vertices[2].first + vertices[2].second == 0)
        return false;

    vertices[0].first = max(vertices[0].first, 1.0);
    vertices[0].second = max(vertices[0].second, 1.0);
    vertices[1].first = max(vertices[1].first, 1.0);
    vertices[1].second = max(vertices[1].second, 1.0);
    vertices[2].first = max(vertices[2].first, 1.0);
    vertices[2].second = max(vertices[2].second, 1.0);
    vertices[0].first = min(vertices[0].first, 99.0);
    vertices[0].second = min(vertices[0].second, 99.0);
    vertices[1].first = min(vertices[1].first, 99.0);
    vertices[1].second = min(vertices[1].second, 99.0);
    vertices[2].first = min(vertices[2].first, 99.0);
    vertices[2].second = min(vertices[2].second, 99.0);
        
    return true;
}

void process()
{
    //process input
    double area = ((vertices[0].first*(vertices[1].second-vertices[2].second)) +
                   (vertices[1].first*(vertices[2].second-vertices[0].second)) +
                   (vertices[2].first*(vertices[0].second-vertices[1].second))) / 2;

    double perimeter = sqrt(pow((vertices[0].first - vertices[1].first), 2) + pow(vertices[0].second - vertices[1].second, 2)) + 
        sqrt(pow((vertices[1].first - vertices[2].first), 2) + pow(vertices[1].second - vertices[2].second, 2)) +
        sqrt(pow((vertices[2].first - vertices[0].first), 2) + pow(vertices[2].second - vertices[0].second, 2));
    printf("%4.0lf\n", ceil(fabs(area) + fabs(perimeter)));
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
