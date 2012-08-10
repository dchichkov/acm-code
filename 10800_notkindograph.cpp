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
char graph[150][150];
char line[60];
int top;
/*global variables*/

void dump()
{
    //dump data
    REP(i, top-1)
    {
        REP(j, strlen(line)+3)
        {
            printf("%c", graph[i][j]);
        }
        printf("\n");
    }
}

bool getInput()
{
    CL2d(graph, ' ', 150, 150);
    CL(line, 0);
    //get input
    scanf("%50s ", line);
    return true;
}

void process()
{
    //process input
    top = 0;
    int row = 1;
    
    REP(i, strlen(line))
    {
        switch (line[i])
        {
        case 'R':
            ++top;
            break;
        case 'C':
            break;
        case 'F':
            --top;
            break;
        }
    }
    if (top < 0)
        row = -(top) + 1;
    else
    {
        row = 1;
        top += 1;
    }
    
    top = abs(top);
    debug(top, endl);

    REP(i, top)
        graph[i][0] = '|';
    graph[top][0] = '+';

    REP(i, strlen(line))
        graph[top][i+1] = '-';


    REP(i, strlen(line))
    {
        switch (line[i])
        {
        case 'R':
            graph[top-row][i+2] = '/';
            row++;
            break;
        case 'C':
            graph[top-row][i+2] = '_';
            break;
        case 'F':
            row--;
            graph[top-row][i+2] = '\\';
            break;
        }
    }
    top += 2;
    dump();
}

int main()
{
    int nc;
    scanf("%d\n", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();

        if (nc != 0)
            printf("\n");
    }

    return 0;
}
