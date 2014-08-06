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
map<string, string> candidate;
map<string, int> votes;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int num;
    scanf("%d ", &num);
    string a, b;
    REP(i, num)
    {
        getline(cin, a);
        getline(cin, b);
        debug(a, TAB);
        dbg(cout << " = ";);
        debug(b, endl);
        candidate[a] = b;
    }
    return true;
}

void process()
{
    //process input
    int num, mxp = 0;
    bool tie = false;
    scanf("%d ", &num);
    string vote;
    REP(i, num)
    {
        getline(cin, vote);
        if (votes.find(vote) != votes.end())
            votes[vote]++;
        else votes[vote] = 1;
    }

    map<string, int>::iterator it, jt;
    for (it = votes.begin(); it != votes.end(); ++it)
    {
        debug(it->second, endl);
        if (mxp < it->second)
        {
            jt = it;
            mxp = it->second;
        }
    }
    for (it = votes.begin(); it != votes.end(); ++it)
    {
        if (mxp == it->second && it != jt)
        {
            tie = true;
            break;
        }
    }
    debug(jt->first, TAB);
    debug(candidate[jt->first], endl);
    debug(jt->first.compare("Marilyn Manson"), endl);
    printf("%s\n", tie ? "tie" : candidate[jt->first].c_str());
}

int main()
{
    int nc;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();
        if (nc > 0) puts("");
        /*CLEAR GLOBAL VARIABLES!*/
        candidate.clear();
        votes.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
