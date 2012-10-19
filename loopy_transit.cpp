#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

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
typedef long long int64; //for clarity
typedef vector<int> vi; //?
typedef vector<point> vp; //?
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } //change min
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } //change max

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
vector<vi> edges;


/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int num_nodes, connections;
    int a, b;
    scanf("%d\n%d", &num_nodes, &connections);
    edges.resize(num_nodes);
    REP(i, connections)
    {
        scanf("%d %d", &a, &b);
        edges[a].push_back(b);
    }
    return true;
}

int c_loops(int node, int prev_node)
{
    if (node == prev_node) return 0;
    debug(node, TAB); debug(prev_node, endl);
    int loops = 0;
    REP(i, edges[node].size())
    {
        debug(loops ,endl);
        if (edges[node][i] == prev_node)
            return loops+1;
        else
            loops = c_loops(i, prev_node);
    }

    return loops;
}


void process()
{
    //process input
    int t_loops = 0;
    REP(i, edges.size())
    {
        t_loops += c_loops(i, edges[i][0]);
    }
    
    printf("%d\n", t_loops);
}

int main()
{

    int nc;
    scanf("%d", &nc);

    while (nc-- > 0)
    {
        getInput();

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        edges.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
