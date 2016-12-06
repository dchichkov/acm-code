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

bool pawn(int i, int j, char& color)
{
    bool isW = isupper(board[i][j]);

    if (isW)
    {
        color = 'b';
        if (board[i-1][j-1] == 'k' || board[i-1][j+1] == 'k')
            return true;
    }
    else
    {
        color = 'w';
        if (board[i+1][j-1] == 'K' || board[i+1][j+1] == 'K')
            return true;
    }

    return false;
}

bool rook(int i, int j, char& color)
{
    bool isW = isupper(board[i][j]);
    bool ischeck = false;
    int x = i;
    while (x-- > 0)
    {
        if (isW)
        {
            color = 'b';
            if (board[x][j] == 'k')
            {
                ischeck = true;
                break;
            }
            else if (board[x][j] != '.')
                break;
        }
        else
        {
            color = 'w';
            if (board[x][j] == 'K')
            {
                ischeck = true;
                break;
            }
            else if (board[x][j] != '.')
                break;
        }
    }
    if (ischeck) return true;
    x = i;
    while (x++ < 11)
    {
        if (isW)
        {
            color = 'b';
            if (board[x][j] == 'k')
            {
                ischeck = true;
                break;
            }
            else if (board[x][j] != '.')
                break;
        }
        else
        {
            color = 'w';
            if (board[x][j] == 'K')
            {
                ischeck = true;
                break;
            }
            else if (board[x][j] != '.')
                break;
        }
    }
    if (ischeck) return true;
    x = j;
    while (x-- > 0)
    {
        if (isW)
        {
            color = 'b';
            if (board[i][x] == 'k')
            {
                ischeck = true;
                break;
            }
            else if (board[i][x] != '.')
                break;
        }
        else
        {
            color = 'w';
            if (board[i][x] == 'K')
            {
                ischeck = true;
                break;
            }
            else if (board[i][x] != '.')
                break;
        }
    }
    if (ischeck) return true;
    x = j;
    while (x++ < 11)
    {
        if (isW)
        {
            color = 'b';
            if (board[i][x] == 'k')
            {
                ischeck = true;
                break;
            }
            else if (board[i][x] != '.')
                break;
        }
        else
        {
            color = 'w';
            if (board[i][x] == 'K')
            {
                ischeck = true;
                break;
            }
            else if (board[i][x] != '.')
                break;
        }
    }
    return ischeck;
}

bool knight(int i, int j, char& color)
{
    bool isW = isupper(board[i][j]);
    if (isW)
    {
        color = 'b';
        if (board[i-2][j+1] == 'k' || board[i-2][j-1] == 'k' ||
            board[i+1][j-2] == 'k' || board[i-1][j-2] == 'k' ||
            board[i+1][j+2] == 'k' || board[i-1][j+2] == 'k' ||
            board[i+2][j-1] == 'k' || board[i+2][j+1] == 'k')
            return true;
    }
    else
    {
        color = 'w';
        if (board[i-2][j+1] == 'K' || board[i-2][j-1] == 'K' ||
            board[i+1][j-2] == 'K' || board[i-1][j-2] == 'K' ||
            board[i+1][j+2] == 'K' || board[i-1][j+2] == 'K' ||
            board[i+2][j-1] == 'K' || board[i+2][j+1] == 'K')
            return true;
    }
    return false;
}

bool bishop(int i, int j, char& color)
{
    bool isW = isupper(board[i][j]);
    bool ischeck = false;

    int x = i-1;
    int y = j+1;
    //diagonal up right
    while (board[x][y] != 0)
    {
        if (isW)
        {
            color = 'b';
            if (board[x][y] == 'k')
            {
                ischeck = true;
                break;
            }
            else if (board[x][y] != '.')
                break;
        }
        else
        {
            color = 'w';
            if (board[x][y] == 'K')
            {
                ischeck = true;
                break;
            }
            else if (board[x][y] != '.')
                break;
        }
        x--;
        y++;
    }

    x = i-1;
    y = j-1;
    if (ischeck) return true;
    //diagonal up left
    while (board[x][y] != 0)
    {
        if (isW)
        {
            color = 'b';
            if (board[x][y] == 'k')
            {
                ischeck = true;
                break;
            }
            else if (board[x][y] != '.')
                break;
        }
        else
        {
            color = 'w';
            if (board[x][y] == 'K')
            {
                ischeck = true;
                break;
            }
            else if (board[x][y] != '.')
                break;
        }
        x--;
        y--;
    }

    x = i+1;
    y = j-1;
    if (ischeck) return true;
    //diagonal down left
    while (board[x][y] != 0)
    {

        if (isW)
        {
            color = 'b';
            if (board[x][y] == 'k')
            {
                ischeck = true;
                break;
            }
            else if (board[x][y] != '.')
                break;
        }
        else
        {
            color = 'w';
            if (board[x][y] == 'K')
            {
                ischeck = true;
                break;
            }
            else if (board[x][y] != '.')
                break;
        }
        x++;
        y--;
    }

    x = i+1;
    y = j+1;
    if (ischeck) return true;
    //diagonal down right
    while (board[x][y] != 0)
    {

        if (isW)
        {
            color = 'b';
            if (board[x][y] == 'k')
            {
                ischeck = true;
                break;
            }
            else if (board[x][y] != '.')
                break;
        }
        else
        {
            color = 'w';
            if (board[x][y] == 'K')
            {
                ischeck = true;
                break;
            }
            else if (board[x][y] != '.')
                break;
        }
        x++;
        y++;
    }
    
    return ischeck;
}

bool queen(int i, int j, char& color)
{
    bool isW = isupper(board[i][j]);
    bool ischeck = false;
    //up
    int x = i;
    while (x-- > 0)
    {
        if (isW)
        {
            color = 'b';
            if (board[x][j] == 'k')
            {
                ischeck = true;
                break;
            }
            else if (board[x][j] != '.')
                break;
        }
        else
        {
            color = 'w';
            if (board[x][j] == 'K')
            {
                ischeck = true;
                break;
            }
            else if (board[x][j] != '.')
                break;
        }
    }
    if (ischeck) return true;
    //down
    x = i;
    while (x++ < 11)
    {
        if (isW)
        {
            color = 'b';
            if (board[x][j] == 'k')
            {
                ischeck = true;
                break;
            }
            else if (board[x][j] != '.')
                break;
        }
        else
        {
            color = 'w';
            if (board[x][j] == 'K')
            {
                ischeck = true;
                break;
            }
            else if (board[x][j] != '.')
                break;
        }
    }
    if (ischeck) return true;
    x = j;
    //left
    while (x-- > 0)
    {
        if (isW)
        {
            color = 'b';
            if (board[i][x] == 'k')
            {
                ischeck = true;
                break;
            }
            else if (board[i][x] != '.')
                break;
        }
        else
        {
            color = 'w';
            if (board[i][x] == 'K')
            {
                ischeck = true;
                break;
            }
            else if (board[i][x] != '.')
                break;
        }
    }
    if (ischeck) return true;
    x = j;
    //right
    while (x++ < 11)
    {
        if (isW)
        {
            color = 'b';
            if (board[i][x] == 'k')
            {
                ischeck = true;
                break;
            }
            else if (board[i][x] != '.')
                break;
        }
        else
        {
            color = 'w';
            if (board[i][x] == 'K')
            {
                ischeck = true;
                break;
            }
            else if (board[i][x] != '.')
                break;
        }
    }

    x = i-1;
    int y = j+1;
    if (ischeck) return true;
    //diagonal up right
    while (board[x][y] != 0)
    {
        if (isW)
        {
            color = 'b';
            if (board[x][y] == 'k')
            {
                ischeck = true;
                break;
            }
            else if (board[x][y] != '.')
                break;
        }
        else
        {
            color = 'w';
            if (board[x][y] == 'K')
            {
                ischeck = true;
                break;
            }
            else if (board[x][y] != '.')
                break;
        }
        x--;
        y++;
    }

    x = i-1;
    y = j-1;
    if (ischeck) return true;
    //diagonal up left
    while (board[x][y] != 0)
    {
        if (isW)
        {
            color = 'b';
            if (board[x][y] == 'k')
            {
                ischeck = true;
                break;
            }
            else if (board[x][y] != '.')
                break;
        }
        else
        {
            color = 'w';
            if (board[x][y] == 'K')
            {
                ischeck = true;
                break;
            }
            else if (board[x][y] != '.')
                break;
        }
        x--;
        y--;
    }

    x = i+1;
    y = j-1;
    if (ischeck) return true;
    //diagonal down left
    while (board[x][y] != 0)
    {

        if (isW)
        {
            color = 'b';
            if (board[x][y] == 'k')
            {
                ischeck = true;
                break;
            }
            else if (board[x][y] != '.')
                break;
        }
        else
        {
            color = 'w';
            if (board[x][y] == 'K')
            {
                ischeck = true;
                break;
            }
            else if (board[x][y] != '.')
                break;
        }
        x++;
        y--;
    }

    x = i+1;
    y = j+1;
    if (ischeck) return true;
    //diagonal down right
    while (board[x][y] != 0)
    {

        if (isW)
        {
            color = 'b';
            if (board[x][y] == 'k')
            {
                ischeck = true;
                break;
            }
            else if (board[x][y] != '.')
                break;
        }
        else
        {
            color = 'w';
            if (board[x][y] == 'K')
            {
                ischeck = true;
                break;
            }
            else if (board[x][y] != '.')
                break;
        }
        x++;
        y++;
    }
    
    return ischeck;
}

bool king(int i, int j, char& color)
{
    bool isW = isupper(board[i][j]);

    if (isW)
    {
        color = 'b';
        if (board[i-1][j-1] == 'k' || board[i-1][j] == 'k' ||
            board[i-1][j+1] == 'k' || board[i][j+1] == 'k' ||
            board[i][j-1] == 'k' || board[i+1][j-1] == 'k' ||
            board[i+1][j] == 'k' || board[i+1][j+1] == 'k')
            return true;
    }
    else
    {
        color = 'w';
        if (board[i-1][j-1] == 'k' || board[i-1][j] == 'k' ||
            board[i-1][j+1] == 'k' || board[i][j+1] == 'k' ||
            board[i][j-1] == 'k' || board[i+1][j-1] == 'k' ||
            board[i+1][j] == 'k' || board[i+1][j+1] == 'k')
            return true;
    }
    return false;
}

void process()
{
    //process input
    bool check = false;
    char color;
    FOR(i, 2, 10)
    {
        FOR(j, 2, 10)
        {
            switch(tolower(board[i][j]))
            {
            case 'p':
                check = pawn(i, j, color);
                if (check) { debug(board[i][j], TAB); debug(i, TAB); debug(j, TAB); }
                break;
            case 'r':
                check = rook(i, j, color);
                if (check) { debug(board[i][j], TAB); debug(i, TAB); debug(j, TAB); }
                break;
            case 'n':
                check = knight(i, j, color);
                if (check) { debug(board[i][j], TAB); debug(i, TAB); debug(j, TAB); }
                break;
            case 'b':
                check = bishop(i, j, color);
                if (check) { debug(board[i][j], TAB); debug(i, TAB); debug(j, TAB); }
                break;
            case 'q':
                check = queen(i, j, color);
                if (check) { debug(board[i][j], TAB); debug(i, TAB); debug(j, TAB); }
                break;
            case 'k':
                check = king(i, j, color);
                if (check) { debug(board[i][j], TAB); debug(i, TAB); debug(j, TAB); }
                break;
            }
            if (check == true) goto out;
        }
    }
out:
    if (check)
        printf("%s king is in check.", color == 'w' ? "white" : "black");
    else
        printf("no king is in check.");
    puts("");
}


int main()
{
    int cnt = 1;
    while (getInput())
    {
        printf("Game #%d: ", cnt++);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        CL2d(board, 0, 12, 12);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
