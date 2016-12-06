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
vi quests;
/*global variables*/

void dump()
{
    //dump data
    REP(i, nums.size())
        printf("%d ", nums[i]);
}

bool getInput()
{
    //get input
    int m, q, a;
    scanf("%d %d ",&m, &q);
    if (!m && !q)
        return false;

    REP(i, m)
        nums.push_back((scanf("%d ", &a), a));

    REP(i, q)
        quests.push_back((scanf("%d ", &a), a));


    return true;
}

void process()
{
    //process input
    SORT(nums);
    REP(i, quests.size())
    {
        if (find(nums.begin(), nums.end(), quests[i]) == nums.end())
            printf("%d not found", quests[i]);
        else
            printf("%d found at %ld", quests[i], abs(lower_bound(nums.begin(),
                                                                 nums.end(),
                                                                 quests[i]) -
                                                     nums.begin())+1);
        puts("");
    }
}

int main()
{
    int cnt = 0;
    while (getInput())
    {
        printf("CASE# %d:\n", ++cnt);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        nums.clear();
        quests.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
