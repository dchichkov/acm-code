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
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
char board[4][4];
int max_rooks;
int num;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    scanf("%d ", &num);
    if (num == 0) return false;
    //get board
    REP(i, num)
    {
        REP(j, num)
        {
            scanf("%c ", &board[i][j]);
        }
    }
    
    return true;
}

int check_pos(char board[4][4])
{
    int rooks = 0;
    REP(i, num)
    {
        REP(j, num)
        {
            if (board[i][j] == 'X' ||
                board[i][j] == 'B' ||
                board[i][j] == 'R')
                continue;
            else
            {
                board[i][j] = 'R';
                int x, y;
            }
            rooks += check_pos(board);
        }
    }
    return rooks;
}

void process()
{
    //process input
    max_rooks = check_pos(board);
}

int main()
{
    while (getInput())
    {
        CL2d(board, 0, 4, 4);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        max_rooks = 0;
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
