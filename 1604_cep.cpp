#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
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
int boards[1<<18];
int final_n;
queue<board> bfs;

//--moves   (initial, e/w, n/s)
char moves[0x60][0x60];
enum {RIGHT = 0, LEFT, DOWN, UP};
/*global variables*/

void dump(const board& cb)
{
    //dump data
    REP(i, 3)
    {
        REP(j, 3)
        {
            printf("%c ", cb.b[i][j]);
        }
        puts("");
    }
    puts("----------");
}

void binary(int number, int binary_x = 1) {
	int remainder;
	if(number <= 1) {
		cout << number;
		return;
	}

	remainder = number%2;
	binary(number >> 1, binary_x++);    
	cout << remainder;
    if (binary_x%2) cout << "|";
}

bool store_board(const board& bo, int a)
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
    if (final_n == n)
    {
        return false;
        cout << "HIT ENDING" << endl;
    }
    if (boards[n] || a > 30)
    {
        //boards[n] = min(boards[n], a);
        dbg(cout << "HIT PREVIOUS" << endl);
        return false;
    }
    boards[n] = a; //min(boards[n], a);
    
    return true;
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

void do_next_move(board boar, int x, int y, char dir, int mv, int from)
{
    debug(x, TAB); debug(y, endl);
    switch(from)
    {
    case RIGHT: //go left
        
        boar.b[x][y-1] = moves[boar.b[x][y]][dir];
        boar.b[x][y] = 'E';
        break;
        
    case LEFT: //go right
        boar.b[x][y+1] = moves[boar.b[x][y]][dir];
        boar.b[x][y] = 'E';
        break;
        
    case UP: //go down
        boar.b[x+1][y] = moves[boar.b[x][y]][dir];
        boar.b[x][y] = 'E';
        break;
        
    case DOWN: //go up
        boar.b[x-1][y] = moves[boar.b[x][y]][dir];
        boar.b[x][y] = 'E';
        break;
        
    }
    dump(boar);
    if (store_board(boar, mv))
        bfs.push(boar);            
}

void iterate(int mov)
{

    while (!bfs.empty())
    {
        board& boar = bfs.front();
        bfs.pop();
        //find 'E'
        int ex_, ey_;
        REP(i, 3)
        {
            REP(j, 3)
            {
                if (boar.b[i][j] == 'E')
                {
                    ex_ = i;
                    ey_ = j;
                    goto out;
                }
            }
        }
    out:
        debug(ex_, TAB); debug(ey_, endl);
        dump(boar);
        if (ex_ == 0 && ey_ == 0) //top-left
        {
            do_next_move(boar, ex_, ey_+1, 'E', mov, RIGHT); //right come left
            do_next_move(boar, ex_+1, ey_, 'N', mov, DOWN); //down come up
        }
        else if (ex_ == 0 && ey_ == 1) //top-middle
        {
            do_next_move(boar, ex_, ey_+1, 'E', mov, RIGHT); //right come left
            do_next_move(boar, ex_, ey_-1, 'E', mov, LEFT); //left come right
            do_next_move(boar, ex_+1, ey_, 'N', mov, DOWN); //down come up
        }
        else if (ex_ == 0 && ey_ == 2) //top-right
        {
            do_next_move(boar, ex_, ey_-1, 'E', mov, LEFT); //left come right
            do_next_move(boar, ex_+1, ey_, 'N', mov, DOWN); //down come up
        }
        else if (ex_ == 1 && ey_ == 0) //middle-left
        {
            do_next_move(boar, ex_-1, ey_, 'N', mov, UP); //top come south
            do_next_move(boar, ex_, ey_+1, 'E', mov, RIGHT); //right come left
            do_next_move(boar, ex_+1, ey_, 'N', mov, DOWN); //down come up
        }
        else if (ex_ == 1 && ey_ == 1) //middle
        {
            do_next_move(boar, ex_-1, ey_, 'N', mov, UP); //top come south
            do_next_move(boar, ex_, ey_+1, 'E', mov, RIGHT); //right come left
            do_next_move(boar, ex_, ey_-1, 'E', mov, LEFT); //left come right
            do_next_move(boar, ex_+1, ey_, 'N', mov, DOWN); //down come up
        }
        else if (ex_ == 1 && ey_ == 2) //middle-right
        {
            do_next_move(boar, ex_-1, ey_, 'N', mov, UP); //top come south
            do_next_move(boar, ex_, ey_-1, 'E', mov, LEFT); //left come right
            do_next_move(boar, ex_+1, ey_, 'N', mov, DOWN); //down come up
        }
        else if (ex_ == 2 && ey_ == 0) //bottom-left
        {
            do_next_move(boar, ex_-1, ey_, 'N', mov, UP); //top come south
            do_next_move(boar, ex_, ey_+1, 'E', mov, RIGHT); //right come left
        }
        else if (ex_ == 2 && ey_ == 1) //bottom-middle
        {
            do_next_move(boar, ex_-1, ey_, 'N', mov, UP); //top come south
            do_next_move(boar, ex_, ey_+1, 'E', mov, RIGHT); //right come left
            do_next_move(boar, ex_, ey_-1, 'E', mov, LEFT); //left come right
        }
        else if (ex_ == 2 && ey_ == 2) //bottom-right
        {
            do_next_move(boar, ex_-1, ey_, 'N', mov, UP); //top come south
            do_next_move(boar, ex_, ey_+1, 'E', mov, RIGHT); //right come left
        }
        mov += 1;
    }
}

void process()
{
    //process input
    dbg( dump(final_board); );
    int n = 0;
    int countdown = 16;
    REP(i, 3)
    {
        REP(j, 3)
        {
            switch (final_board.b[i][j])
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

    final_n = n;
    board start;
    REP(i, 3)
    {
        REP(j, 3)
        {
            start.b[i][j] = 'W';
        }
    }
    start.b[ey-1][ex-1] = 'E';
    store_board(start, 0);
    store_board(final_board, 31);
    bfs.push(start);

    iterate(0);
    debug(boards[n], endl);
}

int main()
{
    moves['W']['E'] = 'B';
    moves['W']['N'] = 'R';
    moves['R']['E'] = 'B';
    moves['R']['N'] = 'W';
    moves['B']['E'] = 'W';
    moves['B']['N'] = 'R';
    while (getInput())
    {
        CL(boards, 0);
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
