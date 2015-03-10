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

/*
 * Move sets:
Pawn
........
........
........
........
...p....
..*.*...
........
........

Rook
...*....
...*....
...*....
...*....
***r****
...*....
...*....
...*....

Bishop
.......*
*.....*.
.*...*..
..*.*...
...b....
..*.*...
.*...*..
*.....*.

Queen
...*...*
*..*..*.
.*.*.*..
..***...
***q****
..***...
.*.*.*..
*..*..*.

King
........
........
........
..***...
..*k*...
..***...
........
........

Knight
........
........
..*.*...
.*...*..
...n....
.*...*..
..*.*...
........ 
 */ 

char board[12][12];

/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    bool isdone = false;
    FOR(i, 2, 10)
    {
        FOR(j, 2, 10)
        {
            scanf("%c ", &board[i][j]);
            if (board[i][j] != '.') isdone = true;
        }
    }
    return isdone;
}

bool king(bool isW, int x, int y)
{
    char chk = isW ? 'K' : 'k';
    if (board[x+1][y] == chk ||
        board[x+1][y+1] == chk ||
        board[x][y+1] == chk ||
        board[x-1][y+1] == chk ||
        board[x-1][y] == chk ||
        board[x-1][y-1] == chk ||
        board[x][y-1] == chk ||
        board[x+1][y-1] == chk)
        return true;
    return false;
}

bool knight(bool isW, int x, int y)
{
    char chk = isW ? 'K' : 'k';
    if (board[x+1][y] == chk ||
        board[x+1][y+1] == chk ||
        board[x][y+1] == chk ||
        board[x-1][y+1] == chk ||
        board[x-1][y] == chk ||
        board[x-1][y-1] == chk ||
        board[x][y-1] == chk ||
        board[x+1][y-1] == chk)
        return true;
    return false;
}


bool rook(bool isW, int x, int y)
{
    char chk = isW ? 'K' : 'k';
    while (x > 0)
    {
        if ()
            }
    return false;
}

bool bishop(bool isW, int x, int y)
{
    char chk = isW ? 'K' : 'k';
    if (board[x+1][y] == chk ||
        board[x+1][y+1] == chk ||
        board[x][y+1] == chk ||
        board[x-1][y+1] == chk ||
        board[x-1][y] == chk ||
        board[x-1][y-1] == chk ||
        board[x][y-1] == chk ||
        board[x+1][y-1] == chk)
        return true;
    return false;
}

bool queen(bool isW, int x, int y)
{
    char chk = isW ? 'K' : 'k';
        if (board[x+1][y] == chk ||
        board[x+1][y+1] == chk ||
        board[x][y+1] == chk ||
        board[x-1][y+1] == chk ||
        board[x-1][y] == chk ||
        board[x-1][y-1] == chk ||
        board[x][y-1] == chk ||
        board[x+1][y-1] == chk)
        return true;
    return false;
}

bool pawn(bool isW, int x, int y)
{
    char chk = isW ? 'K' : 'k';
    if (isW)
    {
        if (board[x+1][y+1] == chk ||
            board[x-1][y+1] == chk)
            return true;
    }
    else
    {
        if (board[x+1][y-1] == chk ||
            board[x-1][y-1] == chk)
            return true;
    }
    return false;
}

void process()
{
    //process input
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        CL2d(board, 0, 10, 10);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
