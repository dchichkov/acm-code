#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

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
int n, m;
class UnionFind
{
private: vi p, rank;
public:
    UnionFind(int N) { rank.assign(N, 0);
        p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i; }
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
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
    
    int countSet(int i)
    {
        int c = 0;
        for (int j = 0; j < p.size(); ++j)
            if (isSameSet(i, j)) c++;
        return c;
    }

    int numDiff()
    {
        vi n = p;
        UN(n);
        for (vi::iterator it = p.begin(); it != p.end(); ++it)
        {
            debug(*it, endl);
        }
        return n.size();
    }
};
UnionFind *dj;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d %d ", &n, &m);
    if (n == 0 && m == 0) return false;
    dj = new UnionFind(n+1);
    int a, b;
    REP(i, m)
    {
        scanf("%d %d ", &a, &b);
        dj->unionSet(a, b);
    }
    return true;
}

void process()
{
    //process input
    for (int i = 1; i <= n; ++i)
        dj->isSameSet(1, i);
    printf("%d\n", dj->numDiff()-1);
}

int main()
{
    int nc = 1;
    while (getInput())
    {
        printf("Case %d: ", nc++);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        delete dj;
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
