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
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
vector<int> nums;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    int c, d;
    scanf("%d ", &c);
    REP(i, c)
    {
        scanf("%d ", &d);
        nums.push_back(d);
    }
    return true;
}

void process()
{
    //process input

    long long cur_max = 1;
    long long sv_max = 0;
    REP(i, nums.size())
    {
        cur_max *= nums[i];
        debug(nums[i], TAB);
        sv_max = max(sv_max, cur_max);
        FOR(j, i+1, nums.size())
        {
            cur_max *= nums[j];
            debug(nums[j], TAB);
            sv_max = max(sv_max, cur_max);
        }
        dbg(cout << endl);
        debug(sv_max, TAB); debug(cur_max, endl);
        sv_max = max(sv_max, cur_max);
        cur_max = 1;
    }

    printf("%lld.\n\n", sv_max);
}

int main()
{
    int count = 0;
    while (getInput())
    {
        printf("Case #%d: The maximum product is ", ++count);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        nums.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
