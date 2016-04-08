#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>

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
struct node
{
    int nxt;
    int val;
};

struct my_comp
{
    bool operator()(const node& a, const node& b)
    {
        return a.val > b.val;
    }
};
vector<multiset<node, my_comp> > life;
int nodes[110];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int n, m;
    int a, b, c;
    scanf("%d %d ", &n, &m);
    REP(i, n)
    {
        scanf("%d ", &a);
        nodes[i] = a;
    }
    life.resize(n);
    node x;
    REP(i, m)
    {
        scanf("%d %d ", &b, &c);
        x.nxt = c;
        x.val = nodes[c];
        life[b].insert(x);
    }
    return true;
}

void process()
{
    //process input
    int i = 0;
    int tot = 0;
    while (life[i].size() != 0)
    {
        tot += life[i].begin()->val;
        i = life[i].begin()->nxt;
    }
    printf("%d %d\n", tot, i);
}

int main()
{
    int tc, c = 0;
    scanf("%d ", &tc);
    while (tc-- > 0)
    {
        printf("Case %d: ", ++c);
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        CL(nodes, 0);
        life.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
