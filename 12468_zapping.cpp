/*
 * Approach: Tried to think of a way to fold the two number lines
 *  (0 - 99 is really 0 - 49, 50 = 49, 60 = 39, 70 = 29, 80 = 19, 90 = 9, 99 = 1)
 *
 *  but I think brute forcing it is a simpler and easier way.
 *
 */ 

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
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int x, y;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d %d ", &x, &y);
    if (x == -1 && y == -1) return false;
    return true;
}

void process()
{
    //process input
    int count_up = 0, count_down = 0;
    for (int i = x; i != y; i = (i+1)%100)
        count_up++;

    for (int i = x; i != y; i = (i == 0 ? i = 99 : i - 1) )
        count_down++;

    printf("%d\n", min(count_up, count_down));
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
