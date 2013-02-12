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
        debug(sides[i], TAB);
    }
    dbg(cout << endl);
}

bool getInput()
{
    //get input
    sides.resize(4);
    scanf("%d %d %d %d", &sides[0], &sides[1], &sides[2], &sides[3]);
    dbg(dump());
    return true;
}

void process()
{
    //process input
    int a = 0, b = 0, c = 0, d = 0;
    SORT(sides);
    a = count(sides.begin(), sides.end(), sides[0]);
    b = count(sides.begin(), sides.end(), sides[1]);
    c = count(sides.begin(), sides.end(), sides[2]);
    d = count(sides.begin(), sides.end(), sides[3]);

    
    if (a % 2 == 0 && b % 2 == 0 && c %2 == 0 && d % 2 == 0 && d != 4)
        d = 2;
    
    switch (d)
    {
    case 4:
        printf("square");
        break;
    case 2:
        printf("rectangle");
        break;
    default:
        if ((sides[0] + sides[1]) > sides[3])
            printf("quadrangle");
        else printf("banana");
        break;
    }
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

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
