#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>

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
#define REP(i,n) FOR(i,0,(int)n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
map<int, int> parents;
int m, n;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d %d ", &m, &n);
    if (m == 0 && n == 0)
        return false;
    int a, b;

    REP(i, m)
    {
        parents[i+1] = 0;
    }

    REP(i, n)
    {
        scanf("%d %d ", &a, &b);
        parents[b]++;
    }
    return true;
}

void process()
{
    //process input
    
    for (int i = 0; i < m; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (parents[j] == i)
            {
                printf("%d ", j);
            }
        }
    }
    puts("");
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        parents.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
