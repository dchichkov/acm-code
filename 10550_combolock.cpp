#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

#define DEBUG
#undef DEBUG //uncomment this line to pull out print statements
#ifdef DEBUG
#define TAB '\t'
#define debug(a, end) cout << #a << ": " << a << end
#else
#define debug(a, end)
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
int a, b, c, d;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (a == 0 &&
        b == 0 &&
        c == 0 &&
        d == 0) return false;
    
    return true;
}

void process()
{
    //process input
    int deg_pnum = 9;
    int degrees = 0;
    debug(a, TAB);    debug(b, TAB);    debug(c, TAB);    debug(d, endl);
    degrees += 720; //first two turns;
    degrees += deg_pnum * (a > b ? a-b : 40-b+a); //stop at the first number, c-wise
    debug(degrees, endl);
    degrees += 360; //one full turn cc-wise
    degrees += deg_pnum * (c > b ? c-b : 40-b+c); //turn cc-wise to second num
    debug(degrees, endl);
    degrees += deg_pnum * (c > d ? c-d : 40-d+c); //turn c-wise to third num
    debug(degrees, endl);

    printf("%d\n", degrees);
}

int main()
{
    while (getInput())
    {

        process();

        /*output*/


        /*output*/
    }

    return 0;
}
