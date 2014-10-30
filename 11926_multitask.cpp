#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <bitset>

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
int n, m;
bitset<1000000> times;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d %d ", &n, &m);
    if (!n && !m) return false;
    return true;
}

void process()
{
    //process input
    int a, b, c;
    bool conflict = false;
    REP(i, n)
    {
        scanf("%d %d ", &a, &b);
        if (conflict) continue;
        FOR(j, a, b)
        {
            if (times.test(j))
            {
                conflict = true;
                break;
            }
            times.set(j);
        }
    }
    
    REP(i, m)
    {
        scanf("%d %d %d ", &a, &b, &c);
        if (conflict) continue;
        int j, k;
        for (j = a, k = b; j <= 1000000 && !conflict; j += c, k += c)
        {
            debug(j, TAB); debug(k, endl);
            k = min(k, 1000000);
            FOR(l, j, k)
            {
                if (times.test(l))
                {
                    conflict = true;
                    break;
                }
                times.set(l);
            }
        }
    }

    printf("%s\n", conflict ? "CONFLICT" : "NO CONFLICT");
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        times.reset();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
