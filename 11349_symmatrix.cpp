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
long long mat[101][101];
int n;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    long long a;
    scanf("N = %d ", &n);
    REP(i, n)
    {
        REP(j, n)
        {
            scanf("%lld ", &a);
            mat[i][j] = a;
            debug(mat[i][j], TAB);
        }
        dbg( puts(""); );
    }
    return true;
}

void process()
{
    //process input
    bool sym = true;
    REP(i, n)
    {
        REP(j, n)
        {
            if (mat[i][j] != mat[n-i-1][n-j-1] ||
                mat[i][j] < 0 ||
                mat[n-i-1][n-j-1] < 0)
            {
                sym = false;
                goto out;
            }
        }
    }
out:
    printf("%s\n", sym ? "Symmetric." : "Non-symmetric.");
}

int main()
{
    int nc;
    scanf("%d ", &nc);
    int count = 0;
    while (nc-- > 0)
    {
        CL2d(mat, 0, 100, 100);
        printf("Test #%d: ", ++count);
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
