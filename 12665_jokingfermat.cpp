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
#define REP(i,n) FOR(i,0,(int)n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int cubes[1001];
int x, y;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    scanf("%d %d ", &x, &y);
    return true;
}

void process()
{
    //process input
    int n = 0;
    long long c;
    int b, e;
    for (int a = x; a <= y; a++)
    {
        for (b = a+1; b <= 1001; b++)
        {
            c = cubes[a] + cubes[b];
            e = c%10;
            c /= 10;
            if (c > y)
                break;
            if (e == 3)
                n++;
        }
        if (b == (a+1)) break;
    }
    printf("%d\n", n*2);
}

int main()
{
    FOR(i, 1, 1001)
    {
        cubes[i] = pow(i, 3);
    }
    debug(sizeof(cubes[1000]), endl);
    int pn = 1;
    while (getInput())
    {
        printf("Case %d: ", pn++);
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
