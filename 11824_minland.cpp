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
vi lands;
const int limit = 5000000;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int a;
    scanf("%d ", &a);
    while (a != 0)
    {
        lands.push_back(a);
        scanf("%d ", &a);
    }
    return true;
}

void process()
{
    //process input
    int mn = 5000001;
    int total;
    int yc;
    debug(lands.size(), endl);
    do
    {
        total = 0;
        yc = 1;
        
        REP(i, (int)lands.size())
        {
            debug(lands[i], TAB);
            total += 2*(pow(lands[i], yc));
            yc++;
            if (total > limit || total < 0) break;
        }
        if (total > 0) mn = min(mn, total);
        debug(mn, TAB); debug(total, endl);
    }
    while (next_permutation(lands.begin(), lands.end()));

    mn > 5000000 ? printf("Too expensive") : printf("%d",mn);
    puts("");
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
        lands.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
