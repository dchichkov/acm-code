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
deque<int>* q;
queue<int>* qone;
int nc;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int np;
    scanf("%d %d ", &np, &nc);
    if (!np && !nc) return false;
    FOR(i, 1, np+1)
        q->push_back(i);
    return true;
}

void process()
{
    //process input
    char command;
    int x, t;
    
    REP(i, nc)
    {
        if (!qone->empty())
        {
            while (!qone->empty())
            {
                printf("%d\n", qone->front());
                qone->pop();
            }
        }
        else
        {        
            debug(q->front(), endl);
            scanf("%c ", &command);
            if (command == 'E')
            {
                scanf("%d ", &x);
                qone->push(x);
            }
            else
            {
                t = q->front();
                q->pop_front();
                printf("%d\n", t);
                q->push_back(t);
            }
        }
    }
}

int main()
{
    int cnt = 0;
    deque<int> q1;
    queue<int> qone1;
    q = &q1;
    qone = &qone1;
    while (getInput())
    {
        printf("Case %d:\n", ++cnt);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        deque<int> q1;
        queue<int> qone1;
        q = &q1;
        qone = &qone1;   
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
