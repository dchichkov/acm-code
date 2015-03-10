#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <numeric>

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
vi calls;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int a;
    int num_calls;
    scanf("%d ", &num_calls);
    REP(i, num_calls)
    {
        scanf("%d ", &a);
        calls.push_back(a);
    }
    return true;
}

void process()
{
    //process input
    int mile = 0, juice = 0;
    REP(i, calls.size())
    {   
        mile += ceil((1+calls[i]) / 30.0) * 10;
        juice += ceil((1+calls[i]) / 60.0) * 15;
        debug(mile, TAB); debug(juice, endl);
    }
    debug(mile, TAB); debug(juice, endl);
    if (mile == juice)
    {
        printf("Mile Juice %d", mile);
    }
    else if (mile < juice)
    {
        printf("Mile %d", mile);
    }
    else
    {
        printf("Juice %d", juice);
    }
    puts("");
}

int main()
{
    int nc, count = 0;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        printf("Case %d: ", ++count);
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        calls.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
