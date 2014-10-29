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
map<int, vector<int> > nums;
int nops;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    int soa;
    int pos = 1;
    int a;
    scanf("%d %d ", &soa, &nops);
    if (feof(stdin)) return false;
    REP(i, soa)
    {
        scanf("%d ", &a);
        nums[a];
        nums[a].push_back(pos);
        pos++;
    }
    
    return true;
}

void process()
{
    //process input
    int a, b;
    REP(i, nops)
    {
        scanf("%d %d ", &a, &b);
        printf("%d\n", ((nums.find(b) == nums.end()) || (nums[b].size() < (a))) ? 0 : nums[b][a-1]);
    }
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        nums.clear();
        nops = 0;
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
