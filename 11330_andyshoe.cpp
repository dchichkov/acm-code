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
typedef vector<int> vi;
typedef vector<point> vp;

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
    //get input
    int n, a;
    scanf("%d ", &n);
    REP(i, n*2)
    {
        scanf("%d ", &a);
        nums.push_back(a);
    }
    return true;
}

int chknms(int i)
{
    while (i < nums.size())
    {
        if (nums[i] != nums[i-1])
            return i;
        i += 2;
    }
    return 0;
}

void process()
{
    //process input
    int i = 1, tf, ttl = 0, z;
    vi::iterator x, y;
    while ((i = chknms(i)) && i != 0)
    {
        tf = nums[i-1];
        y = find(nums.begin()+i, nums.end(), tf);
        x = nums.begin()+i;
        z = *x;
        *x = *y;
        *y = z;
        ++ttl;
        i += 2;
    }
    printf("%d\n", ttl);
}

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        nums.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
