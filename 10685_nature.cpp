#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iterator>

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
vector<string> animals;
int N;
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

    void outRanks()
    {
        for (int i = 0; i < (int)rank.size(); ++i)
            cout << rank[i] << " ";
        cout << endl;
    }

    void outParents()
    {
        for (int i = 0; i < (int)p.size(); ++i)
            cout << p[i] << " ";
        cout << endl;
    }
    
    int countSet(int i)
    {
        int c = 0;
        for (int j = 0; j < (int)p.size(); ++j)
        {
            if (isSameSet(i, j)) c++;
        }
        return c;
    }
};
UnionFind* preds;

int q;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int a;
    scanf("%d %d ", &a, &q);

    debug(a, TAB); debug(q, endl);
    if (a == 0 && q == 0)
        return false;

    char line[1000];
    REP(i, a)
    {
        fgets(line, 1000, stdin);
        line[strlen(line)-1] = 0;
        animals.push_back(line);
        line[0] = 0;
    }

    preds = new UnionFind(a);
    
    return true;
}

void process()
{
    //process input
    char a1[100], a2[100];
    char line[1000];
    REP(i, q)
    {
        fgets(line, 1000, stdin);
        sscanf(line, "%s %s ", a1, a2);
        debug(a1, TAB); debug(a2, endl);
        debug(distance(animals.begin(), find(animals.begin(), animals.end(), a1)), endl);
        debug(distance(animals.begin(), find(animals.begin(), animals.end(), a2)), endl);
        preds->unionSet(distance(animals.begin(), find(animals.begin(), animals.end(), a1)),
                        distance(animals.begin(), find(animals.begin(), animals.end(), a2)));
    }
    int mx_size = 0;
    for (int i = 0; i < (int)animals.size(); ++i)
        mx_size = max(mx_size, preds->countSet(i));

    printf("%d\n", mx_size);
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        animals.clear();
        delete preds;
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
