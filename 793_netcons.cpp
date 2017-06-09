#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>

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
int n;

class UnionFind
{
private: vi p, rank;
public:
    UnionFind(int n) {
        rank.assign(n, 0);
        p.assign(n, 0);
        for (int i = 0; i < n; ++i) p[i] = i;
    }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j)
    {
        if (!isSameSet(i, j))
        {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x;
            else
            {
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++; }
        }
    }
    
    int countSet(int i)
    {
        int c = 0;
        for (int j = 0; j <= n; ++j)
            if (isSameSet(i, j)) c++;
        return c;
    }
};
/*global variables*/

void dump()
{

}

bool getInput()
{
    //get input
    scanf("%d ", &n);
    return true;
}

void process()
{
    //process input
    int succ = 0, unsucc = 0;
    char line[256];
    char c, *dd;
    int c1, c2;
    //debug(n, endl);
    UnionFind connections(n+1);
    dd = fgets(line, 256, stdin);
    if (line[0] == '\n') line[0] = 0;
    while (strlen(line) != 0 && dd != NULL)
    {
        debug(line, TAB); debug(line[0], endl);
        sscanf(line, "%c %d %d", &c, &c1, &c2);

        switch(c)
        {
        case 'c':
            connections.unionSet(c1,c2);
            break;
        case 'q':
            if (connections.isSameSet(c1,c2))
                succ++;
            else
                unsucc++;
            break;
        }
        dd = fgets(line, 256, stdin);
        debug(dd, endl);
        if (line[0] == '\n') line[0] = 0;
    }

    printf("%d,%d\n", succ, unsucc);
}

int main()
{
    int nc;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();
        if (nc != 0)
            puts("");
        /*CLEAR GLOBAL VARIABLES!*/
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
