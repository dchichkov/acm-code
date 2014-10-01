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
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
map<string, map<string, int > > conversion;
map<string, int> convert;    
/*global variables*/

void dump()
{
    //dump data
}

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a%b);
}

bool getInput()
{
    //get input
    int a;
    char unit[10];
    scanf("%d ", &a);
    if (a == 0) return false;
    REP(i, a)
    {
        scanf("%s ", unit);
        conversion[unit];
        convert[unit] = 1;
    }

    char unita[10], unitb[10];
    int amt, amt2 = 0;
    REP(i, a-1)
    {
        scanf("%s = %d %s ", unita, &amt, unitb);
        conversion[unita][unitb] = amt;
        amt2 = gcd(amt, amt2);
    }
    debug(amt2, endl);
    return true;
}

void process()
{
    //process input
    for (map<string, map<string, int> >::iterator it = conversion.begin();
         it != conversion.end(); ++it)
    {
        for (map<string, int>::iterator jt = (it->second).begin();
             jt != (it->second).end(); ++jt)
        {
            if (convert[jt->first] != 1)
                convert[jt->first] = max(convert[jt->first], jt->second) /
                    min(convert[jt->first], jt->second);
            else
                convert[jt->first] = jt->second;
        }
    }

    for (map<string, int>::iterator xt = convert.begin(); xt != convert.end(); ++xt)
    {
        debug((xt->first), TAB); debug((xt->second), endl);
    }
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        convert.clear();
        conversion.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
