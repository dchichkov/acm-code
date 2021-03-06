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
vi ans;
int n;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d ", &n);
    if (n == 0) return false;
    return true;
}

void process()
{
    //process input
    printf("%d\n", ans[n]);
}

int main()
{
    ans.push_back(0);
    ans.push_back(1);
    ans.push_back(2);
    int i = 2;
    printf("%d", 2000000001);
    /*while (ans.size() < 2000000001)
    {
        REP(j, ans[i])
        {
            ans.push_back(i);
            if (ans.size() >= 2000000001) break;
        }
        ++i;
        }*/

    
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
