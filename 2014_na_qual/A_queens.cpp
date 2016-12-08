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
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)
/*global variables*/
char board[8][8];
vp queens;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    point a, b;
    REP(i, 8)
    {
        REP(j, 8)
        {
            scanf("%c ", &board[i][j]);
            if (board[i][j] == '*')
            {
                a.first = i;
                a.second = j;
                queens.push_back(a);
            }
            
        }
        scanf(" ");
    }
    return true;
}

void process()
{
    //process input
    bool valid = true;
    dbg(
        REP(i, 8)
        {
            REP(j, 8)
            {
                printf("%c", board[i][j]);
            }
            puts("");
        }
        );
    if (queens.size() != 8)
    {
        valid = false;
        goto out;
    }
    REP(i, queens.size())
    {
        REP(j, queens.size())
        {
            if (i == j) continue;
            if (queens[i].first == queens[j].first ||
                queens[i].second == queens[j].second ||
                (abs(queens[i].second-queens[j].second) == abs(queens[i].first-queens[j].first)))
            {
                valid = false;
                goto out;
            }
        }
    }
out:
    printf("%s\n", valid ? "valid" : "invalid");
}

int main()
{
    //while ()
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
