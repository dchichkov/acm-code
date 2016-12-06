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
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
char grid[27][27];
int vert[] = {1, 1, 0, -1, -1, -1, 0, 1};
int hori[] = {0, 1, 1, 1, 0, -1, -1, -1};
bool nfirst;
/*global variables*/

void dump()
{
    //dump data
    REP(i, 7)
    {
        REP(j, 7)
        {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

bool getInput()
{
    if (nfirst) printf("\n");
    else nfirst = true;
    
    //get input
    char line[30];
    int i = 1;
    while (true)
    {
        if (feof(stdin)) break;
        fgets(line, 30, stdin);
        debug(line, endl);
        line[strlen(line)-1] = 0;
        if (strlen(line) == 0) break;
        strcpy(&grid[i][1], line);
        ++i;
    }
    return true;
}

void fill(int x, int y, char c)
{
    for (int i = 0; i < 8; ++i)
    {
        if (grid[x + vert[i]][y + hori[i]] == '1')
        {
            grid[x + vert[i]][y + hori[i]] = c;
            fill(x+vert[i], y+hori[i], c);
        }
    }
}

void process()
{
    //process input
    char fillc = 'A';
    int maxn = 0, count;
    //floodfill
    FOR(i, 1, 26)
    {
        FOR(j, 1, 26)
        {
            if (grid[i][j] == '1')
            {
                grid[i][j] = fillc;
                fill(i, j, fillc);
                count = 0;
                REP(k, 27)
                {
                    REP(l, 27)
                    {
                        if (grid[k][l] == fillc) ++count;
                    }
                }
                maxn = max(count, maxn);
                fillc++;
            }
        }
    }
    dbg(dump());
    printf("%d\n", maxn);
}

int main()
{
    CL2d(grid, -1, 27, 27);
    int nc;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        CL2d(grid, -1, 27, 27);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
