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
char players[1000000];
char ladders[120];

int num_players,
    num_rolls,
    num_snl;
/*global variables*/

void dump()
{
    //dump data
    REP(i, 10)
    {
        cout << players[i] << " ";
    }
    cout << endl;
    REP(i, 10)
    {
        cout << ladders[i] << " ";
    }
    cout << endl;
}

bool getInput()
{
    //get input
    scanf("%d %d %d ", &num_players, &num_snl, &num_rolls);
    memset(players, 1, sizeof(char)*num_players);
    int s, e;
    REP(i, num_snl)
    {
        scanf("%d %d ", &s, &e);
        ladders[s] = e;
    }
    
    return true;
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
        debug(c_player, TAB); debug(dice_num, TAB); debug(players[c_player] + dice_num, endl);
        players[c_player] = players[c_player] + dice_num;
        debug(players[c_player], TAB);
        while(ladders[players[c_player]] != -1)
        {
            debug(ladders[players[c_player]], TAB);
            players[c_player] = ladders[players[c_player]];
        }
        dbg(cout << endl);
        
        if (players[c_player] >= 100)
        {
            FOR(j, i+1, num_rolls)
            {
                scanf("%d ", &dice_num);
            }
            break;
        }
    }

    for (int i = 0; i < num_players; ++i)
    {
        printf("Position of player %d is %d.\n", i+1, players[i]);
    }
}

int main()
{
    CL(ladders, -1);
    
    int nc;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        CL(ladders, -1);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
