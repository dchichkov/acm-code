#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>

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
map<string, point> xprts;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int d, p1, p2;
    string m;
    scanf("%d ", &d);
    REP(i, d)
    {
        cin >> m >> p1 >> p2;
        xprts[m];
        xprts[m].first = p1;
        xprts[m].second = p2;
    }
    return true;
}

void process()
{
    //process input
    vector<string> ttl;
    int q, p;
    scanf("%d ", &q);
    REP(i, q)
    {
        scanf("%d ", &p);
        for (map<string, point>::iterator it = xprts.begin(); it != xprts.end(); ++it)
        {
            if (p >= it->second.first && p <= it->second.second)
                ttl.push_back(it->first);
        }

        if (ttl.size() == 1)
            cout << ttl[0];
        else
            cout << "UNDETERMINED";
        cout << endl;
        ttl.clear();
    }
}

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc-- > 0)
    {
        getInput();
        process();
        if (tc != 0) cout << endl;
        /*CLEAR GLOBAL VARIABLES!*/
        xprts.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
