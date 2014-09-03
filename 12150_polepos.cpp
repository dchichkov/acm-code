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
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int nc;
vi cars;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d ", &nc);
    if (nc == 0) return false;
    return true;
}

void process()
{
    //process input
    int a, b;
    bool cd = true;
    cars.resize(nc);
    REP(i, nc)
    {
        scanf("%d %d ", &a, &b);
        debug(i + b, endl);
        if (i + b < 0 ||
            i + b >= nc ||
            cars[i+b] != 0)
            cd = false;
        else
        {
            cars[i + b] = a;
        }
    }
    if (!cd)
        printf("-1");
    else
    {
        printf("%d", cars[0]);
        FOR(i, 1, nc)
        {
            printf(" %d", cars[i]);
        }   
    }
    puts("");
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        cars.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
