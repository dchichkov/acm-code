/* Class:   CSC 2700 Programming Competitions
 * Prof:    Isaac Traxler
 * Name:    Matthew Gavin
 * Problem: 514 - Rails
 *
 * Note: After trying to seduce tricks out of the properties of a stack...
 *       I gave up and simulated it.
 *
 */ 
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>

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
int num_t;
bool f;

stack<int> dummy;
queue<int> trains;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d ", &num_t);
    if (num_t == 0) return false;
    return true;
}

void clear()
{
    while (!dummy.empty())
        dummy.pop();

    while (!trains.empty())
        trains.pop();
}

void process()
{
    //process input
    int t;
    while (true)
    {
        FOR(i, 1, num_t+1)
        {
            trains.push(i);
        }
        dummy.push(0);
        REP(i, num_t)
        {
            scanf("%d ", &t);
            if (t == 0) goto end;
            debug(t, endl);

            while (dummy.top() != t && !trains.empty())
            {
                debug(trains.front(), TAB); debug(trains.empty(), endl);
                dummy.push(trains.front());
                trains.pop();
            }

            if (dummy.top() != t)
            {
                printf("No\n");
                FOR(j, i, num_t-1)
                {
                    scanf("%d ", &t);
                    dbg(cout << "bad t " << t << endl);
                }
                break;
            }
            debug(dummy.top(), endl);
            dummy.pop();

        }
        debug(dummy.top(), endl);
        if (dummy.top() == 0)
            printf("Yes\n");
        clear();

    }
 end:
    clear();
    ;
    printf("\n");
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
