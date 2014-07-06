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
#define LSOne(b) ((b)&(-b))

/*global variables*/
int a, b;
int num;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d ", &num);
    if (num == 0)
        return false;
    return true;
}

void process()
{
    //process input
    while (num > 0)
    {
        debug(LSOne(num), endl);
        a += LSOne(num);
        num -= LSOne(num);
        b += LSOne(num);
        num -= LSOne(num);
    }
    printf("%d %d\n", a, b);
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        a = b = 0;
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
