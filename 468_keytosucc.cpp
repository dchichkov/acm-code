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
map<int, char, std::greater<int> > ans, ans2;
map<char, char> sup;
string enc;
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
    REP(i, line.length())
    {
        frq[line[i]]++;
    }

    getline(cin, line);
    enc = line;
    REP(i, line.length())
    {
        frq2[line[i]]++;
    }

    scanf(" ");
    return true;
}

void process()
{
    //process input
    for (map<char, int>::iterator it = frq.begin(); it != frq.end(); ++it)
        ans[it->second] = it->first;

    for (map<char, int>::iterator it = frq2.begin(); it != frq2.end(); ++it)
        ans2[it->second] = it->first;

    for (map<int, char>::iterator it = ans.begin(), jt = ans2.begin();
         it != ans.end(); ++it, ++jt)
    {
        debug(it->first, TAB); debug(it->second, endl);
        sup[jt->second] = it->second;
        dbg( cout << endl; );
    }

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

        /*CLEAR GLOBAL VARIABLES!*/
        frq.clear(); frq2.clear();
        ans.clear(); ans2.clear();
        sup.clear();
        enc.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
