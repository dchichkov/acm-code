#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define DEBUG
#undef DEBUG //uncomment this line to pull out print statements
#ifdef DEBUG
#define TAB '\t'
#define debug(a, end) cout << #a << ": " << a << end
#else
#define debug(a, end)
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
vector<int> vals;
int N;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    int x, y = 0;
    if (feof(stdin) || scanf("%d", &N) == EOF) return false;
    //get input
    if (N == 0) return true;
    scanf("%d", &x);
    debug(N, endl);
    REP(i, N-1)
    {
        scanf("%d", &y);
        debug(x, TAB); debug(y, endl);
        vals.push_back(abs(y-x));
        x = y;
    }
    return true;
}

void process()
{
    //process input
    FOR(i, 1, N)
    {
        if (count(vals.begin(), vals.end(), i) > 1) break;
        if (count(vals.begin(), vals.end(), i) != 0)
            vals.erase(find(vals.begin(), vals.end(), i));
    }
    debug(vals.size(), endl);
    //for (vi::iterator it = vals.begin(); it != vals.end(); ++it) cout << *it << " "; cout << endl;
    printf("%s\n", vals.size() == 0 ? "Jolly" : "Not jolly");
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        vals.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
