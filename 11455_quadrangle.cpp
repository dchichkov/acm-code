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
vector<int> sides(4, 0);
/*global variables*/

void dump()
{
    //dump data
    REP(i, sides.size())
    {
        debug(i, TAB);
        debug(sides[i], TAB);
    }
    dbg(cout << endl);
}

bool getInput()
{
    //get input
    sides.resize(4);
    scanf("%d ", &sides[0]);
    scanf("%d ", &sides[1]);
    scanf("%d ", &sides[2]);
    scanf("%d ", &sides[3]);

    return true;
}

void process()
{
    //process input
    
    SORT(sides);
    dbg(dump());
    if (sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3])
        printf("square");
    else if (count(sides.begin(), sides.end(), sides[0]) == 2 &&
             count(sides.begin(), sides.end(), sides[2]) == 2)
        printf("rectangle");
    else if (sides[0] + sides[1] + sides[2] > sides[3])
        printf("quadrangle");
    else
        printf("banana");
    
    printf("\n");
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
        sides.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
