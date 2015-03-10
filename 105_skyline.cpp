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
int skyline[10050];
int mn, mx;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int a, b, c;
    scanf("%d %d %d ", &a, &b, &c);
    mn = a;
    while (!feof(stdin))
    {
        FOR(i, a, c)
        {
            skyline[i] = max(skyline[i], b);
        }
        mx = max(mx, c);
        scanf("%d %d %d ", &a, &b, &c);
    }
    return true;
}

void process()
{
    //process input
    int cur;
    cur = skyline[mn];
    printf("%d %d", mn, cur);

    FOR(i, mn, mx+1)
    {
        if (skyline[i] != cur)
        {
            printf(" %d %d", i, skyline[i]);
            cur = skyline[i];
        }
        //printf(" %d", skyline[i]);
    }
    puts("");
}

int main()
{
    //while ()
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
