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
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    int n, a;
    scanf("%d ", &n);
    if (!n) return false;
    //get input
    REP(i, n)
    {
        scanf("%d ", &a);
        nums.push_back(a);
    }
    
    return true;
}

void process()
{
    //process input
    int m, t, x, y;
    scanf("%d ", &m);
    int min = 1<<30;
    REP(i, m)
    {
        min = 1<<30;
        scanf("%d ", &t);
        REP(j, nums.size())
        {
            REP(k, nums.size())
            {
                if (j == k) continue;
                if ((nums[j] + nums[k])-t < 0)
                {
                    if (abs((nums[j] + nums[k])-t) < min)
                    {
                        min = abs(nums[j]+nums[k]-t);
                        x = nums[j];
                        y = nums[k];
                    }
                } else {
                    if ((nums[j] + nums[k])-t < min)
                    {
                        min = nums[j]+nums[k]-t;
                        x = nums[j];
                        y = nums[k];
                    }
                }
            }
        }
        printf("Closest sum to %d is %d.\n", t, x+y);
    }
}

int main()
{
    int count = 0;
    while (getInput())
    {
        printf("Case %d:\n", ++count);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        nums.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
