#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
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
#define REP(i,n) FOR(i,0,(int)n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
queue<int> a, g;
multiset<int> lst;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int na, ng;
    scanf("%d %d ", &na, &ng);
    int t;
    REP(i, na)
    {
        scanf("%d ", &t);
        a.push(t);
    }

    REP(i, ng)
    {
        scanf("%d ", &t);
        g.push(t);
    }
    return true;
}

void print_set()
{
    for (set<int>::iterator it = lst.begin(); it != lst.end(); ++it)
    {
        debug(*it, TAB);
    }
    puts("");
}

void process()
{
    //process input
    int ac = 0, ab = 0, gc = 0;
    multiset<int>::iterator it;

    while (!a.empty())
    {
        
        lst.insert(a.front());
        if (lst.size() == 1) it = lst.begin(); //to play well with iterators
        if(a.front() < *it)
            it--;

//        debug(*it, TAB); dbg(printf("%X\n", it));
        dbg(print_set());
        ac++;
        a.pop();
        
        while (!g.empty() && g.front() == ac)
        {
            if (gc != 0) ++it; //off by 1 error
            printf("%d\n", *it);
            g.pop();
            gc++;
            if (it == lst.end())
                it--;
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

        /*CLEAR GLOBAL VARIABLES!*/
        lst.clear();
        while (!a.empty()) a.pop();
        while (!g.empty()) g.pop();

        if (nc != 0)
            puts("");
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
