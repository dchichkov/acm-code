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
map<char, int> frq, frq2;
map<int, char> frq3;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    string line;
    getline(cin, line);
    if (line.compare("\n") == 0) getline(cin, line);
    REP(i, line.length())
    {
        frq[line[i]]++;
    }
    getline(cin, line);
    REP(i, line.length())
    {
        frq2[line[i]]++;
    }
    return true;
}

void process()
{
    //process input
    map<char, int>::iterator it, jt;
    it = frq.begin();
    jt = frq2.begin();
    int mx = 0;
    for (map<char, int>::iterator xt = frq.begin(); xt != frq.end(); ++xt)
        frq3[xt->second] = xt->first;
    while (it != frq.end())
    {
        debug(it->first, TAB); debug(it->second, TAB);
        debug(jt->first, TAB); debug(jt->second, TAB);
        debug(frq[it->second], endl);
        REP(i, jt->second)
            printf("%c", frq3[it->second]);

        it++;
        jt++;
    }
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

        /*CLEAR GLOBAL VARIABLES!*/
        frq.clear();
        frq2.clear();
        frq3.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
