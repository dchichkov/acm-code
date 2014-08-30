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
priority_queue<int> blue, green;
vi gr, bl;
int bfs;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int nb, ng;
    scanf("%d %d %d ", &bfs, &ng, &nb);
    int a;
    REP(i, ng)
    {
        scanf("%d ", &a);
        green.push(a);
    }
    REP(i, nb)
    {
        scanf("%d ", &a);
        blue.push(a);
    }
    return true;
}

void process()
{
    //process input
    int x, j = 0;
    while (!green.empty() && !blue.empty())
    {
        REP(i, bfs)
        {
            x = green.top();
            j = blue.top();
            green.pop();
            blue.pop();
            if (x > j)
                gr.push_back(x-j);
            else if (j > x)
                bl.push_back(j-x);
            if (green.empty() || blue.empty()) break;
        }
        REP(i, gr.size())
            green.push(gr[i]);
        REP(i, bl.size())
            blue.push(bl[i]);

        gr.clear();
        bl.clear();
    }
    printf("%s\n", (green.empty() && blue.empty()) ? "green and blue died" :
           (green.empty()) ? "blue wins" : "green wins");
    if (!green.empty())
    {
        while (!green.empty())
        {
            printf("%d\n", green.top());
            green.pop();
        }
    }
    else if (!blue.empty())
    {
        while (!blue.empty())
        {
            printf("%d\n", blue.top());
            blue.pop();
        }
    }
}

int main()
{
    int nc;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();
        if (nc != 0) puts("");
        /*CLEAR GLOBAL VARIABLES!*/
        while (!blue.empty())
            blue.pop();

        while (!green.empty())
            green.pop();

        gr.clear();
        bl.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
