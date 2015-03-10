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
int cnt = 1;
char grid[120][120];
int lx, ly, strl, nl;
int mvx[] = {1, 0, -1, 0};
int mvy[] = {0, 1, 0, -1};
/*global variables*/

void dump()
{
    FOR(i, 0, nl+2)
    {
        FOR(j, 0, strl+2)
        {
            printf("%d", grid[i][j]);
        }
        puts("");
    }
}

bool getInput()
{
    //get input
    scanf("%d %d ", &lx, &ly);
    char line[200];
    int i = 1;
    while (fgets(line, 200, stdin), !feof(stdin))
    {
        line[strlen(line)-1] = 0;
        if (strlen(line) == 0) break;
        else
        {
            strl = max(strl, (int)strlen(line));
            FOR(j, 1, strlen(line)+1)
            {
                grid[i][j] = !(line[j-1]-0x30);
            }
        }
        nl = i;
        ++i;
    }
    return true;
}

void floodfill(int x, int y)
{
    REP(i, 4)
    {
        if (grid[x+mvx[i]][y+mvy[i]] == 1)
        {
            grid[x+mvx[i]][y+mvy[i]] = 0;
            cnt++;
            floodfill(x+mvx[i], y+mvy[i]);
        }
    }
}

void process()
{
    //process input
    dbg( dump(); );
    grid[lx][ly] = 0;
    floodfill(lx, ly);
    printf("%d\n", cnt);
}

int main()
{
    int tc;
    scanf("%d ", &tc);
 
    while (tc-- > 0)
    {
        getInput();
        process();
        if (tc != 0) puts("");
        /*CLEAR GLOBAL VARIABLES!*/
        CL2d(grid, 0, 120, 120);
        cnt = 1;
        /*CLEAR GLOBAL VARIABLES!*/
        
    }

    return 0;
}
