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
unsigned long long fib[60];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d ", &n);
    return true;
}

void process()
{
    //process input
    printf("%lld", fib[n]);
}

int main()
{
    fib[1] = 2;
    fib[0] = 1;
    FOR(i, 2, 55)
    {
        fib[i] = fib[i-1] + fib[i-2];
        debug(i, TAB); debug(fib[i], endl);
    }
    
    int nc, count = 0;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        printf("Scenario #%d:\n", ++count);
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
        //if (nc != 0)
            printf("\n\n");
    }

    return 0;
}
