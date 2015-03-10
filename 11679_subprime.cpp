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
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int B[30];
int N[30];
int b, n;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d %d ", &b, &n);
    if (!b && !n) return false;

    int amt;
    FOR(i, 1, b+1)
    {
        scanf("%d ", &amt);
        B[i] = amt;
    }
    return true;
}

void process()
{
    //process input
    int d, c, a;
    REP(i, n)
    {
        scanf("%d %d %d ", &d, &c, &a);
        B[c] += a;
        B[d] -= a;
    }

    bool gtz = true;
    FOR(i, 1, b+1)
    {
        //debug(B[i], endl);
        if (B[i] < 0)
        {
            gtz = false;
            break;
        }
    }

    printf("%s\n", gtz ? "S" : "N");
        
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        CL(B, 0);
        CL(N, 0);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
