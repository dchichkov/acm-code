/*
 * std::map implementation 
 */

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
map<string, string> slogans;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int ns;
    string s1, s2;
    cin >> ns;
    cin.ignore();
    debug(ns, endl);
    REP(i, ns)
    {
        getline(cin, s1);
        getline(cin, s2);
        debug(s1, TAB); debug(s2, endl);
        slogans[s1] = s2;

    }
    return true;
}

void process()
{
    //process input
    string line;
    int nr;
    cin >> nr;
    cin.ignore();
    debug(nr, endl);
    REP(i, nr)
    {
        getline(cin, line);
        cout << slogans[line] << endl;
    }
}

int main()
{
    //while ()
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
