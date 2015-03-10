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
#define REP(i,n) FOR(i,0,(int)n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int graph[210][210];
int sog;
vi colors;

/*global variables*/

void dump()
{
    //dump data
    REP(i, sog)
    {
        REP(j, sog)
        {
            printf(" %2d", graph[i][j]);
        }
        puts("");
    }
}

bool getInput()
{
    //get input
    int e;
    scanf("%d ", &sog);
    if (sog == 0) return false;
    
    colors.resize(sog);
    
    scanf("%d ", &e);
    int a, b;
    REP(i, sog)
    {
        graph[i][i] = -1;
    }
    
    REP(i, e)
    {
        scanf("%d %d ", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;  
    }
    dbg(dump());
    dbg(cout << endl);
    return true;
}

bool dfs(int i, int c)
{
    //int k = 0;
    c = (c == 4 ? 2 : 4);
    colors[i] = c;
    REP(j, sog)
    {
        if (graph[i][j] == 1)
        {
            debug(i, TAB); debug(j, endl);
            graph[i][j] = 3;
            graph[j][i] = 3;
            debug(j, TAB);
            debug(colors[j], TAB); debug(colors[i], endl);
            if (colors[j] == colors[i]) return false;
            if (dfs(j, c) == false)
                return false;
        }
    }
    return true;
}

void process()
{
    //process input
    int j;
    bool bc = true;
    REP(i, sog)
    {
        REP(j, sog)
        {
            if (graph[i][j] == 1)
            {
                debug(i, TAB); debug(j, endl);
                graph[i][j] = 3;
                graph[j][i] = 3;
                colors[i] = 4;
                bc = dfs(j, 4);
            }
            if (!bc) goto end;
        }
    }
end:
    REP(i, colors.size()-1)
    {
        dbg( printf("%d ", colors[i]); );
    }
    dbg( printf("%d\n", colors.back()); );
    dbg( dump(); );
    printf("%sBICOLORABLE.\n", bc ? "" : "NOT ");
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        CL2d(graph, 0, 210, 210);
        colors.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
