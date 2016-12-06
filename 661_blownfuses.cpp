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
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int n,m,c;
vp devices;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d %d %d ", &n, &m, &c);
    if (!(n && m && c)) return false;
    return true;
}

void process()
{
    //process input
    int a;
    point b;
    int total = 0, mx = 0;

    REP(i, n)
    {
        scanf("%d ", &a);
        b.first = a;
        b.second = 0;
        devices.push_back(b);
    }

    REP(i, m)
    {
        scanf("%d ", &a);
        devices[a-1].second = !devices[a-1].second;
        if (devices[a-1].second) total += devices[a-1].first;
        else total -= devices[a-1].first;
        mx = max(total, mx);
        if (total > c)
        {
            FOR(j, i+1, m)
            {
                scanf("%d ", &a);
            }
            break;
        }
    }

    printf("Fuse was %sblown.\n", ((total > c) ? "" : "not "));
    if (total <= c)
        printf("Maximal power consumption was %d amperes.\n", mx);
    puts("");
}

int main()
{
    int count = 0;
    while (getInput())
    {
        printf("Sequence %d\n", ++count);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        devices.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
