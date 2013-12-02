/*
 * This problem isn't about how many unique snowflakes there are,
 * it's about the maximum amount of how many contiguous unique snowflakes there are
 *
 * Backtracking from finding a non-unique snowflake to "reset" the range in which
 * there are unique snowflakes finally let me be able to solve this problem.
 */ 

#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>

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
set<unsigned int> unflakes;
vector<unsigned int> flakes;
long unsigned int maxn;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    unsigned int nf, t;
    scanf("%u ", &nf);
    debug(nf, endl);
    REP(i, nf)
    {
        scanf("%u ", &t);
        debug(t, TAB);
        flakes.push_back(t);
    }
    dbg(cout << endl);
    return true;
}

void process()
{
    //process input
    pair<set<unsigned int>::iterator, bool> rv;
    unsigned int temp;
    for(vector<unsigned int>::iterator it = flakes.begin(); it != flakes.end(); ++it)
    {
        rv = unflakes.insert(*it);
        if (rv.second == false)
        {
            //backup ** this was the fix
            temp = *it;
            while ( *(it-1) != temp ) --it;
            unflakes.clear();
            unflakes.insert(*it);
        }
        
        maxn = max(maxn, unflakes.size());
    }
    printf("%lu\n", maxn);
}

int main()
{
    int nc;
    scanf("%d ", &nc);
    
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        unflakes.clear();
        flakes.clear();
        maxn = 0;
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
