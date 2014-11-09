#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

//#define DEBUG  //comment this line to pull out print statements
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
const long long MAX = 2000000000;
vector<long long> nums;
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
    printf("The %d", n);
    if (n%100 > 10 && n%100 < 14)
        printf("th");
    else if (n%10 == 1)
        printf("st");
    else if (n%10 == 2)
        printf("nd");
    else if (n%10 == 3)
        printf("rd");
    else printf("th");
    printf(" humble number is %lld.\n", nums[n-1]);
}

int main()
{
    long long cur;
    int i, j, k, l;
    for (i = 0;; ++i)
    {
        cur = pow(2, i);
        debug(cur, endl);
        if (cur > MAX || cur < 0) break;
        nums.push_back(cur);
        for (j = 0;; ++j)
        {
            cur = pow(2, i) * pow(3, j);
            debug(cur, endl);
            if (cur > MAX || cur < 0) break;
            nums.push_back(cur);
            for (k = 0;; ++k)
            {
                cur = pow(2, i) * pow(3, j) * pow(5, k);
                if (cur > MAX || cur < 0) break;
                nums.push_back(cur);
                for (l = 0;; ++l)
                {
                    cur = pow(2, i) * pow(3, j) * pow(5, k) * pow(7, l);
                    if (cur > MAX || cur < 0) break;
                    nums.push_back(cur);
                }
            }
        }
    }
    SORT(nums);
    UN(nums);
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
