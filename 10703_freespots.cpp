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

typedef pair<int, int> point;
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,(int)n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
bool pos[550][550];
int w, h, n;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d %d %d ", &w, &h, &n);
    return w+h+n;
}

void process()
{
    //process input
    int cnt = 0;
    int x1, x2, y1, y2;
    REP(i, n)
    {
        scanf("%d %d %d %d ", &x1, &y1, &x2, &y2);
        FOR(j, min(x1, x2)-1, max(x1, x2))
        {
            FOR(k, min(y1, y2)-1, max(y1, y2))
            {
                pos[j][k] = 1;
            }
        }
    }
    FOR(i, 0, w)
    {
        FOR(j, 0, h)
        {
            if (!pos[i][j])
            {
                cnt++;
            }
        }
    }

    if (cnt < 2)
        printf("There is %s empty spot%s.\n", (cnt == 1 ? "one" : "no"), (cnt == 1 ? "" : "s"));
    else
        printf("There are %d empty spots.\n", cnt);
    
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        CL2d(pos, 0, 550, 550);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
