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
struct cddt
{
    int d, p;
    int pos;
};
vector<cddt> jurors;
int m, n;

struct srt
{
    bool operator()(const cddt& a, const cddt& b)
    {
        if (a.d == b.d)
            return a.p < b.p;
        return a.d < b.d;
    }
};
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
    cddt j;
    int i = 0;
    for (; i < n; ++i)
    {
        scanf("%d %d ", &j.p, &j.d);
        j.pos = i+1;
        jurors.push_back(j);
    }
    return true;
}

void process()
{
    //process input
    sort(jurors.begin(), jurors.end(), srt());
    int mn = 0x0FFFFFFF, mx = 0, dx, px;
    vector<int> pos;
    REP(i, n-m)
    {
        dx = px = 0;
        REP(j, m)
        {
            dx += jurors[i+j].d;
            px += jurors[i+j].p;
        }
    }
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        jurors.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
