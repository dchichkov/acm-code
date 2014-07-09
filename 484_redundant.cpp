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
vi nums;
/*global variables*/

void dump()
{
    //dump data
    REP(i, (int)nums.size())
    {
        printf("%d ", nums[i]);
    }
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    int a;
    while (!feof(stdin))
    {
        scanf("%d ", &a);
        nums.push_back(a);
    }
    return true;
}

void process()
{
    //process input
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    dbg( dump(); puts(""); );
    int counts, x;
    vi::iterator it;
    while (nums.size() != 0)
    {
        x = nums[0];
        counts = count(nums.begin(), nums.end(), x);
        printf("%d %d\n", x, counts);
        while ((it = find(nums.begin(), nums.end(), x)) != nums.end())
        {
            nums.erase(it);
        }
        //dbg( dump(); );
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
