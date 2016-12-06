#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <stack>

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
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int arrays;
int refs;

struct arry {
    char name[11];
    int baseaddr;
    int bs;
    vector<pair<int, int> > bounds;
};
    
vector<arry> arrs;
/*global variables*/

void dump()
{
    //dump data
    REP(i, arrs.size())
    {
        printf("name: %s base: %d size: %d -", arrs[i].name, arrs[i].baseaddr, arrs[i].bs);
        REP(j, arrs[i].bounds.size())
        {
            printf(" %d %d", arrs[i].bounds[j].first, arrs[i].bounds[j].second);
        }
        puts("");
    }
}

bool getInput()
{
    //get input
    char name[11];
    int ba;
    int bs;
    int num_dim;
    int ub, lb;
    pair<int, int> bound;
    arry arr;
    REP(i, arrays)
    {
        scanf("%s %d %d %d", name, &ba, &bs, &num_dim);
        strcpy(arr.name, name);
        arr.baseaddr = ba;
        arr.bs = bs;
        REP(j, num_dim)
        {
            scanf("%d %d", &lb, &ub);
            bound.first = lb;
            bound.second = ub;
            arr.bounds.push_back(bound);
        }
        arrs.push_back(arr);
        arr.bounds.clear();
    }
    
    return true;
}

struct find_arrdef {
    string name;
    find_arrdef(string name):name(name){}
    bool operator()(const arry& a)
    {
        debug(name, TAB);
        debug(a.name, TAB);
        debug(name.compare(a.name), endl);
        if (name.compare(a.name) == 0) return true;
        return false;
    }
};

void process()
{
    //process input
    char name[11];
    scanf("%s ", name);
    const arry& a = *(find_if(arrs.begin(), arrs.end(), find_arrdef(name)));
    int num_dims = a.bounds.size();
    int C0 = a.baseaddr;
    int Cnum = a.bs;
    debug(num_dims, TAB);
    debug(C0, TAB);
    debug(Cnum, endl);
    stack<int> cnums;
    for(int i = num_dims-1; i > -1; --i)
    {
        C0 -= Cnum * a.bounds[i].first;
        cnums.push(Cnum);
        Cnum = Cnum * (a.bounds[i].second - a.bounds[i].first + 1);
    }

    debug(C0, endl);
    debug(Cnum, endl);
    int xx, final = C0;

    printf("%s[", name);
    
    REP(j, num_dims)
    {
        scanf("%d ", &xx);
        final += (xx * cnums.top());
        cnums.pop();
        if (j != 0) printf(", %d", xx);
        else printf("%d", xx);
    }
    printf("] = %d\n", final);
    debug(final, endl);
    
}

int main()
{
    scanf("%d %d ", &arrays, &refs);
    getInput();
    //dump();
    while (refs-- > 0)
    {

        process();
    
        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
