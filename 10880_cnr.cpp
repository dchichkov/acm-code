#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

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
int C, R;

vi factors;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d %d", &C, &R);
    debug(C, TAB); debug(R, endl);
    return true;
}

void process()
{
    //process input
    int n = C-R;
    
    //get factors
    int srt = sqrt(n)+1;
    for (int i = 1; i < srt; ++i)
    {
        if (n%i == 0)
        {
            if (i > R)
            {
                debug(i, endl);
                factors.push_back(i);
            }
            if (n/i > R && n/i != i)
            {
                factors.push_back(n/i);
                debug(n/i, endl);
            }
        }
    }

    SORT(factors);

    if (n == 0)
    {
        printf(" 0");
    }
    else if (!factors.empty())
    {
        REP(i, factors.size())
        {
            if (factors[i] < R)
                break;
            printf(" %d", factors[i]);            
        }
    }
    cout << endl;
}

int main()
{
    int nc, count = 0;
    scanf("%d", &nc);
    while (nc-- > 0)
    {
        printf("Case #%d:", ++count);
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        factors.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
