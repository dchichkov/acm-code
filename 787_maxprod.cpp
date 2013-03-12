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
int nums[100];
int cnt;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    if (feof(stdin)) return false;
    
    //get input
    int r, i = 0;
    scanf("%d ", &r);
    while (r != -999999)
    {
        nums[i++] = r;
        scanf("%d ", &r);
    }
    cnt = i;
    return true;
}

void process()
{
    //process input
    long long msf = 1, mtt = 0;
    int j = 0, k = 0, x = 0;

    REP(i, cnt)
    {
        msf *= nums[i];

        if (msf > mtt)
        {
            j = x;
            k = i;
        }
        else if (msf < 0)
        {
            x++;
            msf = 1;
        }
        else if (msf == mtt && j == x)
        {
            k = i;
        }
        mtt = max(msf, mtt);
    }

    printf("%d\n", mtt);
}

int main()
{
    while (getInput())
    {
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        cnt = 0;
        CL(nums, 0);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
