#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <iomanip>

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
struct board
{
    char b[3][3];
} final_board;

int ex, ey;
bool boards[1<<18];

queue<board> bfs;
//--moves   (initial, e/w, n/s)
char moves[3][3] = {{'W', 'B', 'R'},
                    {'B', 'W', 'R'},
                    {'R', 'W', 'B'}};
/*global variables*/

void dump()
{
    //dump data
    REP(i, 3)
    {
        REP(j, 3)
        {
            printf("%c ", final_board.b[i][j]);
        }
        puts("");
    }
}
int binary_x = 1;
void binary(int number) {
	int remainder;
	if(number <= 1) {
		cout << number;
		return;
	}

	remainder = number%2;
	binary(number >> 1);    
	cout << remainder;
    if (binary_x%2) cout << "|";
    binary_x++;
}

void store_board(const board& bo)
{
    int n = 0;
    int countdown = 16;
    REP(i, 3)
    {
        REP(j, 3)
        {
            switch (bo.b[i][j])
            {
            case 'W': //1
                n |= (1 << (countdown));
                break;
            case 'E': //0
                break;
            case 'R': //2
                n |= (2 << (countdown));
                break;
            case 'B': //3 
                n |= (3 << (countdown));
                break;
            }
            countdown -= 2;
        }
    }
    dbg( binary(n); cout << endl; );
    boards[n] = true;
}

bool getInput()
{
    //get input
    scanf("%d %d ", &ex, &ey);
    if (ex == 0 && ey == 0) return false;

    char spot;
    REP(i, 3)
    {
        REP(j, 3)
        {
            scanf("%c ", &spot);
            final_board.b[i][j] = spot;
        }
    }
    return true;
}

void process()
{
    //process input
    dbg( dump(); );
    store_board(final_board);
}

int main()
{
    while (getInput())
    {
        CL(boards, 0);
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
