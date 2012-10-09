#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

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
typedef long long int64; //for clarity
typedef vector<int> vi; //?
typedef vector<point> vp; //?
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } //change min
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } //change max

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
char graph[150][80];
char line[60];
int bot, top;
/*global variables*/

void dump()
{
    //dump data
    for (int i = top; i > bot-2; --i)
    {
        if (strlen(&graph[75-i][0]) == 0) continue;
        REP(j, strlen(&graph[75-i][0]))
        {
            printf("%c", graph[75-i][j]);
        }
        printf("\n");
    }
}

bool getInput()
{
    CL2d(graph, 0, 150, 80);
    CL(line, 0);
    //get input
    scanf("%50s ", line);
    return true;
}

void process()
{
    //process input
    bot = top = 0;
    int row = 0;

    REP(i, strlen(line))
    {
        switch (line[i])
        {
        case 'R':
            graph[75-row][i+2] = '/';
            REP(m, i+2)
                if (graph[75-row][i+2-m] == 0)
                    graph[75-row][i+2-m] = ' ';
            row++;
            top = max(top, row);
            break;
        case 'C':
            top = max(top, row);
            bot = min(bot, row);
            graph[75-row][i+2] = '_';
            REP(m, i+2)
                if (graph[75-row][i+2-m] == 0)
                    graph[75-row][i+2-m] = ' ';
            break;
        case 'F':
            row--;
            graph[75-row][i+2] = '\\';
            REP(m, i+2)
                if (graph[75-row][i+2-m] == 0)
                    graph[75-row][i+2-m] = ' ';
            bot = min(bot, row);
            break;
        }
    }
    int c = 0;
    /*FOR(i, bot-1, top)
    {
        REP(j, strlen(line)+3)
        {
            graph[75-i][j] = (graph[75-i][j] == 0) ? ' ' : graph[75-i][j];
        }
    }*/
    
    FOR(i, bot, top+1)
    {
        REP(j, strlen(line)+3)
        {
            if (graph[75-i][j] != 0)
            {
                c++;
                break;
            }
        }    
    }
    
    graph[75-bot+1][0] = '+';
    REP(i, c)
        graph[75-bot-i][0] = '|';

    FOR(i, 1, strlen(line)+3)
        graph[75-bot+1][i] = '-';
    debug(c, endl);
    debug(top, endl);
    debug(row, endl);
    debug(bot, endl);
    dump();
}

int main()
{
    int nc, count = 0;
    scanf("%d\n", &nc);
    while (nc-- > 0)
    {
        getInput();

        printf("Case #%d:\n", ++count);
        
        process();

        printf("\n");
    }

    return 0;
}
