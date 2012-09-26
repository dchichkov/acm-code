#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

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
unsigned int i, j;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (scanf("%u %u\n", &i, &j) == EOF) return false;
    return true;
}

void process()
{
    unsigned int m = 0, m_ = 0;

    for (int t = min(i,j), x = t; t <= max(i, j); ++t, x = t)
    {
        while (++m_ && x != 1)
        {
            if (x%2)
                x = 3*x+1;
            else
                x /= 2;
        }
        m = max(m, m_);
        m_ = 0;
    }

    printf("%u %u %u\n", i, j, m);
}

int main()
{
    while (getInput())
    {
        debug(i, TAB); debug(j, endl);
        process();

        /*output*/


        /*output*/
    }

    return 0;
}
