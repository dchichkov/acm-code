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

struct csrt
{
    bool operator() (const int& a, const int& b)
    {
        char c[100];
        char d[100];
        sprintf(c, "%d", a);
        sprintf(d, "%d", b);
        strcat(c, d);
        strcat(d, c);

        return strcmp(c, d) == 0;
    }

};
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int n;
    scanf("%d ", &n);

    if (n == 0)
        return false;

    int a;
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
    sort(nums.begin(), nums.end(), csrt());
    REP(i, nums.size())
    {
        printf("%d", nums[i]);
    }
    puts("");
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
