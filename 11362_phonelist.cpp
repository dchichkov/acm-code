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
vector<string> nums;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    string line;
    int a;
    scanf("%d ", &a);
    REP(i, a)
    {
        getline(cin, line);
        nums.push_back(line);
    }
    return true;
}

void process()
{
    //process input
    bool match = false;
    REP(i, nums.size())
    {
        match = false;
        REP(j, nums.size())
        {
            if (i == j) continue;
            if (nums[j].find(nums[i]) != string::npos)
            {
                match = true;
                break;
            }
        }
        if (match) break;
    }
    printf("%s\n", match ? "NO" : "YES");
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
