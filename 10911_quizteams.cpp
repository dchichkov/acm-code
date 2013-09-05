/* Class:   CSC 2700 Programming Competitions
 * Prof:    Isaac Traxler
 * Name:    Matthew Gavin
 * Problem: 10911 - Forming Quiz Teams
 *
 */ 

#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>

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
double map[20][20];

struct house
{
    string name;
    int x, y;
};

vector<house> houses;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int N;
    scanf("%d ", &N);

    if (N == 0) return false;
    N *= 2;
    houses.resize(N);
    REP(i, N)
    {
        cin >> houses[i].name >> houses[i].x >> houses[i].y;
    }

    REP(i, N)
    {
        debug(houses[i].x, TAB); debug(houses[i].y, TAB); debug(houses[i].name, endl);
    }
    
    return true;
}

double dist(int x, int x2, int y, int y2)
{
    return sqrt(pow(x2-x, 2) + pow(y2-y, 2));
}

void process()
{
    set<double> sup;
    //process input
    REP(i, houses.size())
    {
        REP(j, i)
        {
            map[i][j] = dist(houses[i].x, houses[j].x, houses[i].y, houses[j].y);
            map[j][i] = map[i][j];
            sup.insert(map[i][j]);
        }
    }

    REP(i, 10)
    {
        printf("   %3d   ", i);
    }
    printf("\n");
    REP(i, 10)
    {
        printf("%d|", i);
        REP(j, 10)
        {
            printf(" %06.2lf |", map[i][j]);
        }
        printf("\n");
    }
    double amt = 0;
    int j = 0;
    for (set<double>::iterator i = sup.begin(); i != sup.end() && j < 5; ++i, ++j)
    {
        debug(*i, endl);
        amt += *i;
    }
    debug(amt, endl);
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        houses.clear();
        CL2d(map, 0, 20, 20);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
