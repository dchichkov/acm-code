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
vector<vi> nums;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    int a, b, c;
    scanf("%d %d ", &a, &b);
    vi player;
    REP(i, a)
    {
        REP(j, b)
        {
            scanf("%d ", &c);
            player.push_back(c);
        }
        nums.push_back(player);
        player.clear();
    }
    return true;
}

void process()
{
    //proces input
    int cnt = 0;
    REP(i, nums.size())
    {
        if (find(nums[i].begin(), nums[i].end(), 0) == nums[i].end())
            cnt++;
    }
    printf("%d\n", cnt);
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
