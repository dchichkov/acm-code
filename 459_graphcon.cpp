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
char AdjMat[128][128];
/*global variables*/

void dump()
{
    //dump data
    printf(" ");
    for (int i = 'A'; i < 'Z'+1; ++i)
    {
        printf("%c ", i);
    }
    puts("");
    for (int i = 'A'; i < 'Z'+1; ++i)
    {
        printf("%c", i);
        for (int j = 'A'; j < 'Z'+1; ++j)
        {
            printf(" %d", AdjMat[i][j]);
        }
        puts("");
    }
}

bool getInput()
{
    //get input
    char a, b;
    char line[50];
    scanf("%c ", &a);
    FOR(i, 'A', a+1)
        AdjMat[i][i] = 1;
    while (fgets(line, 50, stdin), strlen(line)-1 > 0 &&
           !feof(stdin))
    {
        debug(line, TAB);
        sscanf(line, "%c%c ", &a, &b);
        debug(a, TAB); debug(b, endl);
        AdjMat[a][b] = 1;
        AdjMat[b][a] = 1;
        //if (feof(stdin)) break;
    }
    return true;
}

void dfs(char node)
{
    for (int j = 'A'; j < 'Z'+1; ++j)
    {
        if (AdjMat[node][j] == 1)
        {
            AdjMat[node][j] = 0;
            dfs(j);
        }
    }
}
void process()
{
    //process input
    dbg(dump(););
    int cnt = 0;
    for (int i = 'A'; i < 'Z'+1; ++i)
    {
        for (int j = 'A'; j < 'Z'+1; ++j)
        {
            if (AdjMat[i][j] == 1)
            {
                ++cnt;
                AdjMat[i][j] = 0;
                dfs(j);
            }
        }
    }
    printf("%d\n\n", cnt);
}

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc-- > 0)
    {
        getInput();
        process();

        //if (tc != 0) puts("");
        /*CLEAR GLOBAL VARIABLES!*/
        CL2d(AdjMat, 0, 128, 128);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
