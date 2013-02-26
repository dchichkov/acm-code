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
typedef unsigned long long ull;
ull num;
const ull n = 447213595;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    cin >> num;
    return true;
}

void process()
{
    //process input
    //binary search the answer
    ull low = 1;
    ull m = n, mid = (low+m/2);
    int x = 0;
    ull t = (mid*(mid+1))/2;
    debug(num, endl);
    for (; low <= m && low != n && num != t;//num <= (mid*(mid-1))/2 || num > (mid*(mid+1))/2;
         )
    {
        debug(x, TAB); debug(low, TAB); debug(m, TAB); debug(mid, TAB); debug((mid*(mid+1))/2, endl);
        //if (num == (mid*(mid-1))/2) break;
        (num >= t) ? low = mid+1 : m = mid-1;
        mid = ((low+m)/2);
        ++x;
        t = (mid*(mid+1))/2;
    }
    debug(x, TAB); debug(low, TAB); debug(m, TAB); debug(mid, endl);
    printf("%llu\n", mid);
}

int main()
{
    int nc = 0;
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
