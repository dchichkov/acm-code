#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
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
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
char grid[51][51];
int num_pt;

vector<string> rects;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d", &num_pt);
    if (num_pt == 0) return false;

    char pt;
    int x, y;
    REP(i, num_pt)
    {
        scanf("%c %d %d", &pt, &x, &y);
        grid[x][y] = pt;
    }
    
    return true;
}

void find_rect(char start, int i, int j, int dir)
{
    switch (dir)
    {
    case 1:
        //right
        FOR(x, i, 51)
        {
            if (isalpha(grid[i][x]))
            {
                rects.push_back("");
                rects[rects.size()-1] += grid[i][x];
                find_rect(start, i, x, 2);
            }   
        }
        break;
    case 2:
        //down
        for (int y = i; y >= 0; --y)
        {
            if (isalpha(grid[y][j]))
            {
                rects[rects.size()-1] += grid[y][j];
                find_rect(start, y, j, 3);
            }
        }
        break;
    case 3:
        //left
        for (int x = j; x >= 0; --x)
        {
            if (isalpha(grid[i][x]))
            {
                rects[rects.size()-1] += grid[i][x];
                find_rect(start, i, x, 4);
            }
        }
        break;
    case 4:
        //up
        FOR(y, j, 51)
        {
            if (isalpha(grid[y][j]) && grid[y][j] != start)
                rects.erase(rects.begin()+rects.size()-1);
        }
        break;
    }
}

void process()
{
    //process input
    REP(i, 51)
    {
        REP(j, 51)
        {
            if (isalpha(grid[i][j])) find_rect(grid[i][j], i, j, 1);
        }
    }

    
    SORT(rects);
    if (rects.size() == 0)
        printf(" No rectangles");
    else
    {
        printf("\n");
        REP(i, (int)rects.size())
        {
            if (i % 10 == 0)
                printf("\n");
            else
                cout << " " << rects[i];
        }
    }
}

int main()
{
    int nc = 0;
    while (getInput())
    {
        CL2d(grid, 0, 51, 51);
        printf("Point set %d:", nc++);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        rects.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
