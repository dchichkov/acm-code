#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

#define DEBUG
//#undef DEBUG //uncomment this line to pull out print statements
#ifdef DEBUG
#define TAB '\t'
#define debug(a, end) cout << #a << ": " << a << end
#else
#define debug(a, end)
#endif

typedef pair<int, int> point;
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
struct compart
{
    int ux, uy, s;
    int lx, ly;
};

int nc;
int np;

compart ments[4];
point pred[5];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    if (scanf("%d", &nc) == EOF) return false;
    REP(i, nc)
    {
        scanf("%d %d %d", &ments[i].ux, &ments[i].uy, &ments[i].s);
        ments[i].lx = ments[i].ux+ments[i].s;
        ments[i].ly = ments[i].uy+ments[i].s;
    }

    scanf("%d", &np);
    REP(i, np)
    {
        scanf("%d %d", &pred[i].first, &pred[i].second);
    }
    
    //get input
    return true;
}

void process()
{
    //process input
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
