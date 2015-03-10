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
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
map<char, int> frq, frq2;
map<char, char> sup;
string enc;
string l1, l2;
struct sorter
{
    bool operator() (const char& a, const char& b)
    {
        return frq[a] > frq[b];
    }
};

struct sorter2
{
    bool operator() (const char& a, const char& b)
    {
        return frq2[a] > frq2[b];
    }
};
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    getline(cin, l1);
    getline(cin, l2);
    enc = l2;

    REP(i, l1.length())
        frq[l1[i]]++;
    REP(i, l2.length())
        frq2[l2[i]]++;

    scanf(" ");
    return true;
}

void process()
{
    //process input
    sort(l1.begin(), l1.end(), sorter());
    sort(l2.begin(), l2.end(), sorter2());
    debug(l1, TAB); debug(l2, endl);
    l1.erase(unique(l1.begin(), l1.end()), l1.end());
    l2.erase(unique(l2.begin(), l2.end()), l2.end());
    debug(l1, TAB); debug(l2, endl);
    REP(i, l1.length())
        sup[l2[i]] = l1[i];

    debug(enc, endl);
    REP(i, enc.length())
        printf("%c", sup[enc[i]]);
    
    puts("");
        
}

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc-- > 0)
    {
        getInput();
        process();
        if (tc != 0) puts("");
        /*CLEAR GLOBAL VARIABLES!*/
        frq.clear(); frq2.clear(); sup.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
