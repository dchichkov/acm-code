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
char a[100], b[100];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    scanf("%s ", a);
    scanf("%s ", b);
    return true;
}

void process()
{
    //process input
    long long c, d;
    int i, j;
    for (i = 36; i > 1; --i)
    {
        c = strtoll(a, NULL, i);
        if (c == 0) continue;
        for (j = 2; j < 37; ++j)
        {
            d = strtoll(b, NULL, j);
            if (d == 0) continue;
            //debug(c, TAB); debug(d, endl);
            if (c == d) goto out;
        }
    }
out:
    if (i == 1)
        printf("%s is not equal to %s in any base 2..36", a, b);
    else
        printf("%s (base %d) = %s (base %d)", a, i, b, j);
    puts("");
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        CL(a, 0);
        CL(b, 0);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
