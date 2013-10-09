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

struct player
{
    player():pos(1){}
    int pos;
};
vector<player> players;

struct ladder
{
    int start, end;
};
vector<ladder> ladders;

int num_players,
    num_rolls,
    num_snl;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d %d %d ", &num_players, &num_snl, &num_rolls);
    players.resize(num_players);

    ladder l;
    REP(i, num_snl)
    {
        scanf("%d %d ", &l.start, &l.end);
        ladders.push_back(l);
    }
    
    return true;
}

void check_ladders(int& x)
{
    for (vector<ladder>::iterator it = ladders.begin(); it != ladders.end(); ++it)
    {
        if (x == it->start)
        {
            x = it->end;
            check_ladders(x);
            break;
        }
    }
}

void process()
{
    //process input
    int dice_num;
    int c_player; //current player
    REP(i, num_rolls)
    {
        scanf("%d ", &dice_num);
        c_player = i % num_players;
        debug(dice_num, TAB); debug(c_player, endl);
        players[c_player].pos = min((players[c_player].pos + dice_num), 100);
        debug(players[c_player].pos, endl);
        check_ladders(players[c_player].pos);
        if (players[c_player].pos == 100)
        {
            dbg(cout << "wtf?");
            FOR(j, i+1, num_rolls)
            {
                scanf("%d ", &dice_num);
                dbg(cout << "breaking loop " << dice_num << endl);
            }
            break;
        }
    }

    int i = 1;
    for (vector<player>::iterator it = players.begin(); it != players.end(); ++it, ++i)
    {
        printf("Position of player %d is %d.\n", i, it->pos);
    }
}

int main()
{
    int nc;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        players.clear();
        ladders.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
