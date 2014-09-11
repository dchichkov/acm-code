#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <limits>

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
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
map<int, int> fibs;
vi fibnums;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int n, a;
    scanf("%d ", &n);
    REP(i, n)
    {
        scanf("%d ", &a);
        fibnums.push_back(a);
    }
    return true;
}

void process()
{
    //process input
    string line;
    getline(cin, line);
    debug(line, endl);
    REP(i, fibnums.size())
    {
        printf("%c", line[fibnums[i]]);
    }

    puts("");
}

int main()
{
    fibs[0] = 0;
    fibs[1] = 1;

    for (int i = 2; fibs[fibs[i-2] + fibs[i-3]] < numeric_limits<int>::max(); ++i)
    {
        fibs[fibs[i-1] + fibs[i-2]] = i;
    }
    
    int tc;
    scanf("%d ", &tc);
    while (tc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        fibnums.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
