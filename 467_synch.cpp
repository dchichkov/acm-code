#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <sstream>

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
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
vi signals;
stringstream lne;
/*global variables*/

void dump()
{
    //dump data
}

int gcd(int a, int b)
{
    return (b == 0) ? a : gcd(b, a%b);
}

int lcm(int a, int b)
{
    return (a * (b/gcd(a,b)));
}

bool getInput()
{
    //get input
    if (cin.eof()) return false;
    string line;
    getline(cin, line);
    lne.str(line);
    return true;
}

void process()
{
    //process input
    int a;
    while (!lne.eof())
    {
        lne >> a;
        debug(a, TAB);
        signals.push_back(a);
    }

    int lm = signals[0];
    FOR(i, 1, (int)signals.size())
    {
        lm = lcm(lm, signals[i]);
    }

    debug(lm, endl);
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        signals.clear();
        lne.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
