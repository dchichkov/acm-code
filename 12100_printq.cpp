#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>

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
queue<int> printq;
vi priorities;
int mypri, mypos;
/*global variables*/

void dump()
{
    //dump data
    queue<int> uh;
    while (!printq.empty())
    {
        uh.push(printq.front());
        debug(printq.front(), endl);
        printq.pop();
    }

    while (!uh.empty())
    {
        printq.push(uh.front());
        uh.pop();
    }
}

bool getInput()
{
    //get input
    int nj, a;
    scanf("%d %d ", &nj, &mypos);
    REP(i, nj)
    {
        scanf("%d ", &a);
        priorities.push_back(a);
    }
    mypri = priorities[mypos];
    for (vector<int>::iterator it = priorities.begin();
         it != priorities.end(); ++it)
        printq.push(*it);
    SORT(priorities);
    return true;
}

void process()
{
    //process input
    dbg( dump(); );
    int t, cnt = 1;
    while (mypos != 0 || mypri < priorities.back())
    {
        t = printq.front();
        printq.pop();
        debug(mypos, TAB); debug(mypri, TAB); debug(t, TAB); debug(priorities.back(), endl);
        if (t < priorities.back())
            printq.push(t);
        else
        {
            cnt++;
            priorities.pop_back();
        }
        mypos--;
        if (mypos < 0)
            mypos = printq.size()-1;

    }
    printf("%d\n", cnt);
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
        priorities.clear();
        while (!printq.empty()) printq.pop();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
