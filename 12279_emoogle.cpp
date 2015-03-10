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
    //get input
    int numnums, t;
    scanf("%d ", &numnums);
    if (numnums == 0) return false;
    REP(i, numnums)
    {
        scanf("%d ", &t);
        nums.push_back(t);
    }
    return true;
}

void process()
{
    //process input

    int n0 = count(nums.begin(), nums.end(), 0);
    printf("%d\n", (int)(nums.size() - (2*n0)));
}

int main()
{
    int count = 1;
    while (getInput())
    {
        printf("Case %d: ", count++);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        nums.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
