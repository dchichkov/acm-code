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
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int m, n;
map<char, int> ccount;
int mx;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int x, y;
    scanf("%d %d %d %d ", &x, &y, &m, &n);
    string line;
    REP(i, x)
    {
        getline(cin, line);
        REP(j, line.length())
        {
            ccount[line[j]] = ccount[line[j]] + 1;
            debug(ccount[line[j]], endl);
            mx = max(mx, ccount[line[j]]);
        }
    }
    return true;
}

void process()
{
    //process input
    int total = 0;
    vector<char> mxs;
    debug(mx, endl);
    for(map<char, int>::iterator it = ccount.begin(); it != ccount.end(); ++it)
    {
        debug(it->second, TAB); debug(it->first, endl);
        if (it->second == mx) mxs.push_back(it->first);
    }

    REP(i, mxs.size())
    {
        debug(ccount[mxs[i]], endl);
        total += ccount[mxs[i]] * m;
        ccount[mxs[i]] = 0;
    }

    for(map<char, int>::iterator it = ccount.begin(); it != ccount.end(); ++it)
        total += it->second * n;
    printf("%d\n", total);
}

int main()
{
    int count = 0;
    int nc;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        mx = 0;
        getInput();
        printf("Case %d: ", ++count);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        ccount.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
