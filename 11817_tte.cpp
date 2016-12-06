#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

#define DEBUG
#undef DEBUG //uncomment this line to pull out print statements
#ifdef DEBUG
#define TAB '\t'
#define debug(a, end) cout << #a << ": " << a << end
#define dbg(end) end
#else
#define debug(a, end)
#define dbg(end)
#endif

typedef pair<int, int> point;
typedef long long int64; //for clarity
typedef vector<int> vi; //?
typedef vector<point> vp; //?
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } //change min
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } //change max

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
double sLat, sLong;
double eLat, eLong;

const double PI = acos(-1.0);
const double radius = 6371009;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%lf %lf %lf %lf", &sLat, &sLong, &eLat, &eLong);
    return true;
}

void process()
{
    //process input
    //GREAT CIRCLE DISTANCE WOOOH! with lat and long being -west, +north, +east, -south
    sLat *= PI/180;
    sLong *= PI/180;
    eLat *= PI/180;
    eLong *= PI/180;

    double angle = acos( cos(sLat)*cos(sLong)*cos(eLat)*cos(eLong) +
                         cos(sLat)*sin(sLong)*cos(eLat)*sin(eLong) +
                         sin(sLat)*sin(eLat) );

    dbg(cout.setf(ios::fixed));
    debug(angle, endl);
    
    double q, p;
    q = radius*angle;
    p = sqrt(2*(radius*radius)*(1-cos(angle))); //law of cosines

    debug(q, endl);
    debug(p, endl);
    debug(round(q - p), endl);
    
    long long d = round(q-p);
    printf("%lld\n", d);
}

int main()
{
    int nc;
    scanf("%d", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
