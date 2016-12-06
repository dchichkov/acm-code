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
vi sales;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int nm, a;
    scanf("%d ", &nm);
    REP(i, nm)
    {
        scanf("%d ", &a);
        sales.push_back(a);
    }
    return true;
}

void process()
{
    //process input
    vi sles;
    int gt;
    FOR(i, 1, (int)sales.size())
    {
        gt = 0;
        REP(j, i)
        {
            if (sales[j] <= sales[i]) gt++;
        }
        sles.push_back(gt);
    }
    printf("%d\n", accumulate(sles.begin(), sles.end(), 0));
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
        sales.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
