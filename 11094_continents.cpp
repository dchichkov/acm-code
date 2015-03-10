#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>

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
char mat[30][30];
int h, w, sx, sy;
char land, water;
int mvx[] = {1, 0, -1, 0};
int mvy[] = {0, 1, 0, -1};
set<char> choices;
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
    if (feof(stdin)) return false;
    char line[50];
    FOR(i, 1, h+1)
    {
        fgets(line, 50, stdin);
        REP(j, strlen(line)-1)
        {
            mat[i][j+1] = line[j];
            choices.insert(line[j]);
        }
    }
    scanf("%d %d ", &sx, &sy);
    sx++, sy++;
    land = mat[sx][sy];
    choices.erase(land);
    water = (*choices.begin());
    return true;
}

int floodfill(int x, int y)
{
    int ttl = 1, zz;
    mat[x][y] = water;
    REP(i, 4)
    {
        zz = y+mvy[i];
        debug(zz, endl);
        if (zz > h)
            zz = 0;
        if (zz < 1)
            zz = h;
        if (mat[x+mvx[i]][zz] == land)
            ttl += floodfill(x+mvx[i],zz);
    }

    return ttl;
}

void process()
{
    //process input
    int ttl = 0;
    int cnt = 0;
    floodfill(sx, sy);
    FOR(i, 1, h+1)
    {
        FOR(j, 1, w+1)
        {
            if (mat[i][j] == land)
            {
                debug(i, TAB); debug(j, endl);
                cnt = floodfill(i, j);
                debug(cnt, endl);
            }
            ttl = max(cnt, ttl);
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
        CL2d(mat, 0, 30, 30);
        choices.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
