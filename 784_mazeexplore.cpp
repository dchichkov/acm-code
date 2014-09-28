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
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
char maze[50][100];

int mvx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int mvy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int i;
char separator[100];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    char line[100];
    bool read = false;
    i = 1;
    
    fgets(line, 100, stdin);
    REP(z, strlen(line)-1)
        if (line[z] != '_') read = true;
    while (read)
    {
        read = false;
        REP(j, strlen(line)-1)
        {
            maze[i][j+1] = line[j];
        }
        ++i;
        fgets(line, 100, stdin);
        REP(z, strlen(line)-1)
            if (line[z] != '_') read = true;
        if (!read)
            strcpy(separator, line);
    }
    return true;
}

void floodfill(int x, int y)
{
    maze[x][y] = '#';
    REP(i, 8)
    {
        if (maze[x+mvx[i]][y+mvy[i]] == ' ')
            floodfill(x+mvx[i], y+mvy[i]);
    }
}

void process()
{
    //process input
    int x, y;
    FOR(k, 1, i)
    {
        FOR(j, 1, 100)
        {
            if (maze[k][j] == '*')
            {
                x = k;
                y = j;
                goto out;
            }
        }
    }
out:
    floodfill(x, y);

    FOR(k, 1, i)
        printf("%s\n", &maze[k][1]);
    printf("%s", separator);
}

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        CL2d(maze, 0, 50, 100);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
