#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <numeric>

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

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a%b);
}

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int nn, n1;
    scanf("%d ", &nn);
    if (nn == 0) return false;

    REP(i, nn)
    {
        scanf("%d ", &n1);
        nums.push_back(n1);
    }
    return true;
}

void process()
{
    //process input
    int total = accumulate(nums.begin(), nums.end(), 0);
    int a = total / nums.size();
    int b = total % nums.size();
    int c = nums.size();

    //first line, numerator
    if (b != 0)
    {
        int div = gcd(b, c);
        b /= div;
        c /= div;
        if (a < 0)
            printf("%5d", b);
        else
            printf("%3d", b);
    }

    //second line
    if (total < 0)
    {
        printf("- ");
    }
    printf("%d");
    
}

int main()
{
    int count = 0;
    while (getInput())
    {
        printf("Case %d:", ++count);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        nums.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
