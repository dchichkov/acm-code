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
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,(int)n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/

/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    return true;
}

void process()
{
    //process input
    printf("%10d%10d\n"
           "%10d%10d\n"
           "%10d%10d\n"
           "%10d%10d\n"
           "%10d%10d\n"
           "%10d%10d\n"
           "%10d%10d\n"
           "%10d%10d\n"
           "%10d%10d\n"
           "%10d%10d\n", 6, 8, 35, 49, 204, 288, 1189, 1681, 6930,
           9800, 40391, 57121, 235416, 332928, 1372105, 1940449,
           7997214, 11309768, 46611179, 65918161);
}

int main()
{
//    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
