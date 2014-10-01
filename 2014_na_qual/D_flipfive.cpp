#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <queue>

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
bitset< 1<<9 > states;
struct cells
{
    char cell[5][5];
};
queue<cells> ntt;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    char line[10];
    FOR(i, 1, 4)
    {
        fgets(line, 10, stdin);
        if (line[strlen(line)-1] == '\n') line[strlen(line)-1] = 0;
        FOR(j, 1, 4)
        {
            cells.cell[i][j] = line[j];
        }
    }
    
    return true;
}

int convert(cell board[5][5])
{
    int mask = 0;
    FOR(i, 1, 4)
    {
        FOR(j, 1, 4)
        {
            if (board[i][j].color == '*')
            {
                mask |= (1 << (i*j)+j);
            }
        }
    }
    return mask;
}

void store(int mask)
{
    states.set(mask, 1);
}

void process()
{
    //process input
    
    int nm = 0;
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
        states.reset();
        CL2d(cells, 0, 5, 5);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
