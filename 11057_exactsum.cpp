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
int nnums;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    scanf("%d ", &nnums);
    return true;
}

void process()
{
    //process input
    vector<int> nums;
    int n;
    REP(i, nnums)
    {
        scanf("%d ", &n);
        nums.push_back(n);
    }

    scanf("%d ", &n); //target

    SORT(nums);
    int t = 0, p1 = 0, p2 = nums.size()-1, p3, p4;

    while(p1 < p2)
    {
        if (nums[p1] + nums[p2] > n)
        {
            p2--;
        }
        else if (nums[p1] + nums[p2] < n)
        {
            p1++;
        }
        else if (nums[p1] + nums[p2])
        {
            p3 = p1;
            p4 = p2;
            p1++;
            p2--;
        }
    }
    
    printf("Peter should buy books whose prices are %d and %d.\n\n", nums[p3], nums[p4]);
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
