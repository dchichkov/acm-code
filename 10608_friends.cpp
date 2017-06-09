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
int N;
class UnionFind
{
private: vi p, rank;
public:
    UnionFind(int N) { rank.assign(N, 0);
        p.assign(N, 0); for (int i = 0; i <  N; ++i) p[i] = i; }
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
        for (int j = 0; j <= N; ++j)
            if (isSameSet(i, j)) c++;
        return c;
    }
};
UnionFind* friends;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    int M;
    scanf("%d %d ", &N, &M);
    int a, b;
    friends = new UnionFind(N+1);
    REP(i, M)
    {
        scanf("%d %d ", &a, &b);
        friends->unionSet(a, b);
    }
    return true;
}

void process()
{
    //count largest totals
    int mx = 0;
    
    for (int i = 0; i <= N; ++i)
    {
        mx = max(friends->countSet(i), mx);
    }
    printf("%d\n", mx);
}

int main()
{
    int nc = 0;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        delete friends;
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
