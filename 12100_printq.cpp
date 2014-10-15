#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>

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
queue<int> printq;
vi priorities;
int myp;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int nj, a;
    scanf("%d %d ", &nj, &myp);
    REP(i, nj)
    {
        scanf("%d ", &a);
        priorities.push_back(a);
    }
    myp = priorities[myp];
    for (vector<int>::reverse_iterator it = priorities.rbegin(); it != rend(); ++it)
        printq.push(*it);
    return true;
}

void process()
{
    //process input
}

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        mx = 0;
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
