#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>

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
unsigned long long ans;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int days;
    scanf("%d ", &days);
    if (days == 0) return false;
    multiset<int> receipts;

    int a, b;
    REP(i, days)
    {
        scanf("%d ", &a);
        REP(j, a)
        {
            scanf("%d ", &b);
            receipts.insert(b);
        }
        if (receipts.size() > 1)
        {
            debug(*(receipts.begin()), TAB);
            debug(*(receipts.rbegin()), endl);
            ans += *(receipts.rbegin()) - *(receipts.begin());

            receipts.erase(--receipts.end());
            receipts.erase(receipts.begin());
        }
    }
    
    
    return true;
}

void process()
{
    //process input
    printf("%llu\n", ans);
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        ans = 0;
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
