#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

#define DEBUG
#undef DEBUG //uncomment this line to pull out print statements
#ifdef DEBUG
#define TAB '\t'
#define debug(a, end) cout << #a << ": " << a << end
#define dbg(end) end
#else
#define debug(a, end)
#define dbg(end)
#endif

typedef pair<int, int> point;
typedef long long int64; //for clarity
typedef vector<int> vi; //?
typedef vector<point> vp; //?
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } //change min
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } //change max

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
vector<int> lst;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int n;
    if (scanf("%d", &n) == EOF) return false;
    lst.push_back(n);
    return true;
}

void process()
{
    //process input

    int n;
    SORT(lst);
    if (lst.size() % 2 == 0)
    {
        debug(*(lst.begin()+(lst.size()/2)), endl);
        debug(*(lst.begin()+(lst.size()/2+1)), endl);
        n = (*(lst.begin()+(lst.size()/2-1)) + *(lst.begin()+(lst.size()/2)))/2;
    }
    else
        n = *(lst.begin()+(lst.size()/2));

    printf("%d\n", n);
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
