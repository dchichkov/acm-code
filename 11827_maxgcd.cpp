#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <sstream>

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
vector<int> nums;

template<typename T>
T gcd (T a, T b)
{
    return b == 0 ? a : gcd(b, a%b);
}
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int n;
    string s;
    getline(cin, s);

    istringstream iss(s);

    while ((iss >> n))
        nums.push_back(n);
    
    return true;
}

void process()
{
    //process input
    int maxn = 0;
    
    REP(i, nums.size())
    {
        REP(j, nums.size())
        {
            if (i == j) continue;
            maxn = max(gcd<int>(nums[i], nums[j]), maxn);
        }
    }

    printf("%d\n", maxn);
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
