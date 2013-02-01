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
char b[4][4];
int max_rooks;
int num;
/*global variables*/

void dump()
{
    //dump data
    REP(i, num)
    {
        REP(j, num)
        {
            printf("%c", b[i][j]);
        }
        printf("\n");
    }     
}

void dump(char** board)
{
    //dump data
    REP(i, num)
    {
        REP(j, num)
        {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
        
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
            scanf("%c ", &b[i][j]);
        }
    }

    return true;
}

void fill_xy(char** board, int i, int j, char aff)
{
    int x1 = i, x2 = i;
    int y1 = j, y2 = j;
    while (--x1 >= 0)
    {
        //left
        if (board[x1][j] == 'X')
            break;
        if (board[x1][j] == '.')
            board[x1][j] = aff;
    }
    while (++x2 < num)
    {
        //right
        if (board[x2][j] == 'X')
            break;
        if (board[x2][j] == '.')
            board[x2][j] = aff;
    }
    while (--y1 >= 0)
    {
        //up
        if (board[i][y1] == 'X')
            break;
        if (board[i][y1] == '.')
            board[i][y1] = aff;
    }
    while (++y2 < num)
    {
        //down
        if (board[i][y2] == 'X')
            break;
        if (board[i][y2] == '.')
            board[i][y2] = aff;
    }
}

void clear_xy(char** board, int i, int j, char aff)
{
    int x1 = i, x2 = i;
    int y1 = j, y2 = j;
    while (--x1 >= 0)
    {
        //left
        if (board[x1][j] == 'X')
            break;
        if (board[x1][j] == aff)
            board[x1][j] = '.';
    }
    while (++x2 < num)
    {
        //right
        if (board[x2][j] == 'X')
            break;
        if (board[x2][j] == aff)
            board[x2][j] = '.';
    }
    while (--y1 >= 0)
    {
        //up
        if (board[i][y1] == 'X')
            break;
        if (board[i][y1] == aff)
            board[i][y1] = '.';
    }
    while (++y2 < num)
    {
        //down
        if (board[i][y2] == 'X')
            break;
        if (board[i][y2] == aff)
            board[i][y2] = '.';
    }
}

void process(char** b1, int rc)
{
    char** board;
    board = new char*[num];
    REP(m, num)
    {
        board[m] = new char[num];
    }
    REP(i, num)
    {
        REP(j, num)
        {
            board[i][j] = b1[i][j];
        }
    }
    //process input
    REP(i, num)
    {
        REP(j, num)
        {
            if (board[i][j] == '.')
            {
                //valid spot
                board[i][j] = 'R';
                fill_xy(board, i, j, 'B'+rc);
                rc++;
                max_rooks = max(max_rooks, rc);
                process(board, rc);
                //undo rook mods for next iter;
                board[i][j] = '.';
                rc--;
                clear_xy(board, i, j, 'B'+rc);
            }
        }
    }

    REP(m, num)
    {
        delete[] board[m];
    }
    delete[] board;
}

int main()
{

    while (getInput())
    {
        char** board;
        board = new char*[num];
        REP(m, num)
        {
            board[m] = new char[num];
        }
        REP(i, num)
        {
            REP(j, num)
            {
                board[i][j] = b[i][j];
            }
        }

        process(board, 0);
        printf("%d\n", max_rooks);
        /*CLEAR GLOBAL VARIABLES!*/
        max_rooks = 0;
        
        /*CLEAR GLOBAL VARIABLES!*/
        REP(m, num)
        {
            delete[] board[m];
        }
        delete[] board;
    }

    return 0;
}
