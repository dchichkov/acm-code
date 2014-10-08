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
int ntr;
vi nums;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d ", &ntr);
    int in, a;
    scanf("%d ", &in);
    REP(i, in)
    {
        scanf("%d ", &a);
        nums.push_back(a);
    }
    return true;
}

void process()
{
    //process input
    int sum;
    bool kewl = false;
    for (int i = 0; i < (1 << nums.size()); ++i)
    {
        sum = 0;
        for (int j = 0; j < nums.size(); ++j)
            if (i & (1 << j)) sum += nums[j];
        if (kewl = (sum == ntr))
            break;
    }
    printf("%s\n", kewl ? "YES" : "NO");
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