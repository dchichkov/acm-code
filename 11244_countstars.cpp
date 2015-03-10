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
char mat[150][150];
int h, w;

int mvx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int mvy[] = {0, 1, 1, 1, 0, -1, -1, -1};
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d %d ", &h, &w);

    debug(h, TAB); debug(w, endl);
    if (!h && !w) return false;
    char line[200];
    FOR(i, 1, h+1)
    {
        fgets(line, 200, stdin);
        REP(j, strlen(line)-1)
        {
            mat[i][j+1] = line[j];
        }
    }
    return true;
}

int floodfill(int x, int y)
{
    int ttl = 0;
    mat[x][y] = '-';
    REP(i, 8)
    {
        if (mat[x+mvx[i]][y+mvy[i]] == '*')
            ttl += floodfill(x+mvx[i],y+mvy[i]);
    }

    return ttl + 1;
}

void process()
{
    //process input
    int ttl = 0;
    int cnt = 0;
    FOR(i, 1, h+1)
    {
        FOR(j, 1, w+1)
        {
            cnt = 0;
            if (mat[i][j] == '*')
            {
                debug(i, TAB); debug(j, endl);
                cnt = floodfill(i, j);
                debug(cnt, endl);
            }
            if (cnt == 1)
                ++ttl;
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
        CL2d(mat, 0, 150, 150);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
