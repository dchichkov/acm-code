#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <limits>

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

struct rat_nest
{
    int x, y;
    int pop;
};

vector<rat_nest> nests;

int d;
int map[1030][1030];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int num_nests;
    rat_nest rn;
    scanf("%d %d", &d, &num_nests);
    
    REP(i, num_nests)
    {
        scanf("%d %d %d ", &rn.x, &rn.y, &rn.pop);
        nests.push_back(rn);
    }
    return true;
}

void process()
{
    //process input
    int x = 0, y = 0, amt = 0;

    REP(i, nests.size())
    {
        FOR(j, max(0, nests[i].x - d), min(1025, nests[i].x + d)+1)
        {
            FOR(k, max(0, nests[i].y - d), min(1025, nests[i].y + d)+1)
            {
                map[j][k] += nests[i].pop;
//                debug(j, TAB); debug(k, TAB); debug(map[j][k], endl);
            }
        }
    }

    REP(i, 1025)
    {
        REP(j, 1025)
        {
            if (amt < map[i][j])
            {
                amt = map[i][j];
                x = i;
                y = j;
            }
        }
    }
    
    printf("%d %d %d\n", x, y, amt);
}

int main()
{
    int num_scenes;
    scanf("%d ", &num_scenes);
    while (num_scenes-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        nests.clear();
        CL2d(map, 0, 1030, 1030);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}

