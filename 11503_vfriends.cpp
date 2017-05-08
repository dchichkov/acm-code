#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>

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
map<string, int> name_num;
class UnionFind
{
private: vi p, rank, count;
public:
    UnionFind(int N) { rank.assign(N, 0); count.assign(N, 1);
        p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i; }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j)
    {
        if (i > p.size()-1 || j > p.size()-1)
        {
            int t = max(i, j)+1;
            int tt = p.size();
            p.resize(t, 0);
            for (; tt < t; ++tt)
                p[tt] = tt;

            rank.resize(t, 0);
            count.resize(t, 1);
        }

        if (!isSameSet(i, j))
        {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x;
            else
            {
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }

            count[x] = count[x] + count[y];
            count[y] = count[x];
        }
    }
    
    int size()
    {
        return p.size();
    }

    void show()
    {
        for (int i = 0; i < p.size(); ++i)
            cout << p[i] << " ";
    }
    
    int countSet(int i)
    {        
        return count[findSet(i)];
    }
};

UnionFind* vfriends;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{    
    //get input
    int nfriends = 5;

    vfriends = new UnionFind(nfriends);
   
    return true;
}

void process()
{
    //process input
    char n1[25], n2[25];
    string ns1, ns2;
    int fsize = 0;
    
    int ntimes;
    scanf("%d ", &ntimes);
    while (ntimes-- > 0)
    {
        scanf("%s %s ", n1, n2);
        debug(n1, TAB); debug(n2, endl);
        ns1 = n1;
        ns2 = n2;
        debug(ns1, TAB); debug(ns2, endl);
        if (name_num.find(ns1) == name_num.end() && ++fsize)
            name_num[ns1] = fsize;

        if (name_num.find(ns2) == name_num.end() && ++fsize)
            name_num[ns2] = fsize;

        debug(name_num[ns1], TAB); debug(name_num[ns2], endl);
        vfriends->unionSet(name_num[ns2], name_num[ns1]);
        debug(name_num.size(), TAB); debug(vfriends->size(), endl);
        dbg(vfriends->show(); cout << endl;);
        
        printf("%d\n", vfriends->countSet(name_num[ns2]));
    }
}

int main()
{
    name_num.clear();
    
    int nc;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        delete vfriends;
        name_num.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
