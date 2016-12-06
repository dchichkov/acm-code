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
int N;
bool notfirst;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d ", &N);
    if (!N) return false;
    if (notfirst) puts("");
    else notfirst = true;
    return true;
}

void process()
{
    //process input
    bool sol = 0;
    for (int fghij = 1234; fghij <= 98765 / N; fghij++)
    {
        int abcde = fghij * N;
        int tmp, used = (fghij < 10000);
        tmp = abcde; while (tmp) { used |= 1 << (tmp % 10); tmp /= 10; }
        tmp = fghij; while (tmp) { used |= 1 << (tmp % 10); tmp /= 10; }
        if (used == (1<<10) - 1)
        {
            sol = true;
            printf("%0.5d / %0.5d = %d\n", abcde, fghij, N);
        }
    }
    if (!sol) printf("There are no solutions for %d.\n", N);
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
