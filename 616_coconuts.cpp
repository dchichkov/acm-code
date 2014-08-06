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
int numc;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d ", &numc);
    if (numc < 0) return false;
    return true;
}

void process()
{
    //process input
    int maxp = 0;
    int leftover;
    for(int i = sqrt(numc)+1; i > 1; --i)
    {
        leftover = numc;
        if (leftover % i != 1) continue;
        REP(j, i)
        {
            debug(leftover, TAB); debug(i, endl);
            if (leftover % i != 1)
            {
                maxp = 0;
                break;
            }
            else maxp = i;
            leftover -= ((leftover/i)+1);
        }
        if (maxp != 0 && (leftover % maxp == 0)) break;
    } 
    printf("%d coconuts, ", numc);
    if (maxp != 0)
        printf("%d people and 1 monkey", maxp);
    else
        printf("no solution");

    puts("");
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
