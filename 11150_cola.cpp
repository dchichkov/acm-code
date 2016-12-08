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
int n;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (scanf("%d ", &n) == EOF) return false;
    return true;
}

void process()
{
    //process input
    int total = 0;
    int borrowed = 0;
    int leftover = 0;
    int p;
    
    debug(n, TAB);
    if (n == 2) { total = 3; goto done; }
    while (n > 0)
    {
        total += n;
        n += leftover;
        leftover = n%3;
        p = n/3;
        if (!borrowed && (p + leftover + 1)%3 == 0)
        {
            borrowed++;
            leftover++;
        }
        n = n/3;
    }
done:
    printf("%d\n", total);
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
