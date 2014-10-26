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
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int h, len;
bool states[10000][2];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d %d ", &h, &len);
    if (h == 0) return false; // && len == 0) return false;
    return true;
}

void process()
{
    //process input
    int cnt = 0;
    int a;
    
    int m = h;
    FOR(i, 0, len)
    {
        scanf("%d ", &a);
        if (a < m)
            cnt += m-a;
        m = a;
    }
    printf("%d\n", cnt);
}

int main()
{
    while (getInput())
    {
        
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        CL2d(states, 0, 10000, 2);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
