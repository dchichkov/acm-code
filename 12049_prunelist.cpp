#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map> 

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
map<int, int> nums;

/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int a, b, n;
    scanf("%d %d ", &a, &b);
    REP(i, a)
    {
        scanf("%d ", &n);

        nums[n]++;        
    }

    REP(i, b)
    {
        scanf("%d ", &n);
        nums[n]--;
    }
    
    return true;
}

void process()
{
    //process input
    int cnt = 0;
    for (map<int,int>::iterator it = nums.begin(); it != nums.end(); ++it)
        cnt += abs(it->second);
    printf("%d\n", cnt);
}

int main()
{
    int nc;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        nums.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
