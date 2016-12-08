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
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int rooms[210][2];
int ntc;
int a;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int x, y;
    scanf("%d %d ", &a, &ntc);
    REP(i, a)
    {
        REP(j, 2)
        {
            scanf("%d ", &rooms[i][j]);
            /*if (i > 0) rooms[i][j] += rooms[i-1][j];
            if (j > 0) rooms[i][j] += rooms[i][j-1];
            if (i > 0 && j > 0) rooms[i][j] -= rooms[i-1][j-1];*/
        }
    }
    return true;
}

void process()
{
    //process input
    int mn = 10000;
    int cnt = 0;
    while (cnt < ntc)
    {
        mn = 10000;
        REP(i, a)
        {
            REP(j, 2)
            {
                mn = min(mn, rooms[i][j]);
            }
        }
        REP(i, a)
        {
            REP(j, 2)
            {
                if (rooms[i][j] == mn)
                {
                    cnt++;
                    rooms[i][j] = 666 - mn;
                }
            }
        }
    }

    REP(i, a-1)
    {
        REP(j, 2)
        {
            if (rooms[i][j] >= 101)
            {
                int x, z, zz, zzz;
                x = i+1;
                int mx = 0;
                REP(y, 2)
                {
                    zzz = abs(y-j);
                    if (rooms[x][zzz] > 100)
                    {
                        if (mx < abs(666-rooms[x][zzz]))
                        {
                            z = x;
                            zz = y;
                            mx = abs(666-rooms[x][zzz]);
                        }
                    }
                }
                rooms[z][zz] = mx;
            }
        }
    }
    
    REP(i, a)
    {
        REP(j, 2)
        {
            printf("%d\t", rooms[i][j]);
        }
        puts("");
    }
}

int main()
{
    CL2d(rooms, 0, 210, 2);
    //while ()
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
