#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

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
vi nums;
bool ugh;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int k;
    scanf("%d ", &k);
    if (k != 0 && ugh)
    {
        puts("");
    }
    if (!ugh) ugh = !ugh;
    if (k == 0) return false;
    int a;
    nums.reserve(k);
    REP(i, k)
    {
        scanf("%d ", &a);
        nums.push_back(a);
    }
    return true;
}

void process()
{
    //process input
    FOR(a, 0, nums.size())
    {
        FOR(b, a+1, nums.size())
        {
            FOR(c, b+1, nums.size())
            {
                FOR(d, c+1, nums.size())
                {
                    FOR(e, d+1, nums.size())
                    {
                            FOR(f, e+1, nums.size())
                            {
                                printf("%d %d %d %d %d %d\n", nums[a], nums[b], nums[c],
                                       nums[d], nums[e], nums[f]);
                            }
                    }
                }
            }
        }
    }
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        nums.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
