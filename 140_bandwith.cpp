#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <limits>

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
set<char> nodes;
map<char, string> edges;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    char line[150];
    char node;
    char edge[50];
    fgets(line, 150, stdin);
    
    if (strcmp(line, "#\n") == 0) return false;
    line[strlen(line)-1] = ';';
    line[strlen(line)] = 0;
    debug(line, endl);
    char* omg = strtok(line, ";");
    while (omg != NULL)
    {
        sscanf(omg, "%c:%s", &node, edge);
        nodes.insert(node);
        REP(i, strlen(edge))
            nodes.insert(edge[i]);
        edges[node] = edge;
        omg = strtok(NULL, ";");
    }
    
    return true;
}

void process()
{
    //process input
    vector<char> oops;
    for (set<char>::iterator it = nodes.begin(); it != nodes.end(); ++it)
    {
        debug(*it, endl);
        oops.push_back(*it);
    }

    int mn = numeric_limits<int>::max();
    int ttl;
    int mx;

    vector<char> ans;
    ans.resize(oops.size());
    do
    {
        ttl = 0;
        mx = 0;
        REP(i, oops.size())
            for (int j = 0; j < edges[oops[i]].length(); ++j)
                mx = max(mx, (int)abs(find(oops.begin(), oops.end(), oops[i])
                                      - find(oops.begin(), oops.end(), edges[oops[i]][j])));
        if (mx < mn)
        {
            mn = mx;
            copy(oops.begin(), oops.end(), ans.begin());
        }

    } while(next_permutation(oops.begin(), oops.end()));

    printf("%c", ans[0]);
    FOR(i, 1, ans.size())
        printf(" %c", ans[i]);
    printf(" -> %d\n", mn);
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        nodes.clear();
        edges.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
