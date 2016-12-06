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
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int bins[3][3];

int configs[6][3][3] = { {{0,1,1}, {3,0,3}, {2,2,0}},
                         {{0,1,1}, {2,0,2}, {3,3,0}},
                         {{0,3,3}, {1,0,1}, {2,2,0}},
                         {{0,3,3}, {2,0,2}, {1,1,0}},
                         {{0,2,2}, {1,0,1}, {3,3,0}},
                         {{0,2,2}, {3,0,3}, {1,1,0}}};
char ans[6][4] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB" };
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    REP(i, 3)
    {
        if (scanf("%d %d %d", &bins[i][0], &bins[i][1], &bins[i][2]) == EOF)
            return false;
    }
    return true;
}

void process()
{
    //process input
    int calc = 0, j, mint = 0x0FFFFFFF;

    REP(i, 6)
    {
        REP(k, 3)
        {
            REP(l, 3)
            {
                if (configs[6-i-1][k][l] != 0)
                {
                    calc += bins[l][configs[6-i-1][k][l]-1];
                }
            }
        }
        
        if (calc <= mint)
        {
            mint = calc;
            debug(calc, TAB);
            j = 6-i-1;
            debug(j, endl);
        }
        calc = 0;
    }

    printf("%s %d\n", ans[j], mint);
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
