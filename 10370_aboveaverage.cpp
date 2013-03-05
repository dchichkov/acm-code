#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <numeric>

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
vector<int> scores;

struct counter
{
    double n;
    counter(double x):n(x){}
    bool operator() (const int& a)
    {
        if (a > n)
            return true;
        return false;
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
    int n, m;
    scanf("%d ", &n);
    REP(i, n)
    {
        scanf("%d ", &m);
        scores.push_back(m);
    }
    
    return true;
}

void process()
{
    long t;
    t = accumulate(scores.begin(), scores.end(), 0);
    double avg = (double)t / scores.size();


    int c = count_if(scores.begin(), scores.end(), counter(avg));
    printf("%0.3lf%%\n", ((double)c / scores.size())*100);
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
        scores.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
