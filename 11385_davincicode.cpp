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
map<int, int> fibss;
vector<unsigned int> fibs;
vi fibnums;
int omg;
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
        debug(a, endl);
        omg = max(omg, fibss[a]);
    }
    return true;
}

void process()
{
    //process input
    string line, l2;
    getline(cin, line);
    debug(omg, endl);
    l2.resize(omg+1, ' ');
    int i = 0;
    REP(j, line.length())
    {
        if (isupper(line[j]))
        {
            l2[fibss[fibnums[i]]] = line[j];
            ++i;
        }
        if (i == fibnums.size()) break;
    }
    printf("%s", l2.c_str());
    puts("");
}

int main()
{
    fibs.push_back(1);
    fibs.push_back(2);

    for (int i = 2; fibs[i-1] < numeric_limits<int>::max(); ++i)
        fibs.push_back(fibs[i-1] + fibs[i-2]);

    REP(i, fibs.size())
        fibss[fibs[i]] = i;

    int tc;
    scanf("%d ", &tc);
    while (tc-- > 0)
    {
        omg = 0;
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        fibnums.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
