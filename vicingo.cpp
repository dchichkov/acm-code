#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

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
#define CL2D(a, s, len, wid) memset(a, s, sizeof(a[0][0])*len*wid)

/*global variables*/
const int LENGTH = 11, WIDTH = 11;
char board[LENGTH][WIDTH];

char white_num = '2';
char black_num = '3';
char bad_spot = '9';

char black = 'X';
char white = 'O';
char empty = '.';

int rangex[4] = {1, 0, -1, 0};
int rangey[4] = {0, 1, 0, -1};
/*global variables*/

char opposite(char c)
{
    if (c == black)
        return white;
    else return black;
}

void dump()
{
    //dump data
    for (int i = 0; i < LENGTH; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
            printf("%c", board[i][j]);
        printf("\n");
    }   
}

void getInput()
{
    for (int i = 1; i < LENGTH-1; ++i)
        for (int j = 1; j < WIDTH-1; ++j)
            scanf("%c%*[\n]", &board[i][j]);
}

void floodfill(int x, int y, char check)
{
    for (int i = 0; i < 4; ++i)
    {
        if (board[x+rangex[i]][y+rangey[i]] == empty)
        {
            char c;
            (check == white) ? c = white_num : c = black_num;
            board[x+rangex[i]][y+rangey[i]] = c;
            //floodfill again
            floodfill(x+rangex[i], y+rangey[i], check);
        }
    }
}

void floodfill_bad(int x, int y)
{
    for (int i = 0; i < 4; ++i)
    {
        if (board[x+rangex[i]][y+rangey[i]] == black_num ||
            board[x+rangex[i]][y+rangey[i]] == white_num)
        {
            board[x+rangex[i]][y+rangey[i]] = bad_spot;
            //floodfill again
            floodfill_bad(x+rangex[i], y+rangey[i]);
        }
    }
}

void check_bounds(int x, int y, char check)
{
    for (int i = 0; i < 4; ++i)
    {
        if (board[x+rangex[i]][y+rangey[i]] == opposite(check))
        {
            debug(x, TAB); debug(y, TAB); debug(x+rangex[i], TAB);
            debug(y+rangey[i], endl);
            board[x][y] = bad_spot;
            break;
        }
    }
}

int main()
{
    int num_sets = 0;
    int total_white = 0;
    int total_black = 0;
    scanf("%d%*[ \n\t]", &num_sets);
    while (num_sets-- > 0)
    {
        getInput();

        //count total pieces
        for (int i = 1; i < LENGTH-1; ++i)
            for (int j = 1; j < WIDTH-1; ++j)
                if (board[i][j] == black)
                    total_black++;
                else if (board[i][j] == white)
                    total_white++;
        debug(total_black, endl);
        debug(total_white, endl);
        //dump();

        //fill territories
        for (int i = 1; i < LENGTH-1; ++i)
            for (int j = 1; j < WIDTH-1; ++j)
                if (board[i][j] == black ||
                    board[i][j] == white)
                    floodfill(i, j, board[i][j]);

        //dump();
        //infect
        for (int i = 1; i < LENGTH-1; ++i)
        {
            for (int j = 1; j < WIDTH-1; ++j)
            {
                if (board[i][j] == white_num)
                    check_bounds(i, j, white);
                else if (board[i][j] == black_num)
                    check_bounds(i, j, black);
            }
        }
        
        //fill adjacent bad spots
        for (int i = 1; i < LENGTH-1; ++i)
            for (int j = 1; j < WIDTH-1; ++j)
                if (board[i][j] == bad_spot)
                    floodfill_bad(i, j);

        //dump();
        
        //count again
        
        for (int i = 1; i < LENGTH-1; ++i)
            for (int j = 1; j < WIDTH-1; ++j)
                if (board[i][j] == black_num)
                    total_black++;
                else if (board[i][j] == white_num)
                    total_white++;        
        
        printf("Black %d White %d\n", total_black, total_white);
        
        //clear board, totals
        CL2D(board, 0, LENGTH, WIDTH);
        total_white = total_black = 0;
    }

    return 0;
}
