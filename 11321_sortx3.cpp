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
int M;

struct srt
{
    bool operator()(const int& a, const int& b)
    {
        int rema = a%M;
        int remb = b%M;
        int c = abs(a), d = abs(b);
        if (rema == remb)
        {
            if (c % 2 == 1 && d % 2 == 1)
            {
                return a > b;
            }
            else if ((c % 2 == 1) && (d % 2 == 0))
            {
                return 1;
            }
            else if ((c % 2 == 0) && (d % 2 == 1))
            {
                return 0;
            }
            if ((c % 2 == 0) && (d % 2 == 0))
            {
                return a < b;
            }
        }
        else
            return rema < remb;
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
    int N;
    scanf("%d %d ", &N, &M);
    printf("%d %d\n", N, M);
    if (!N && !M)
        return false;

    int a;
    REP(i, N)
    {
        scanf("%d ", &a);
        nums.push_back(a);
    }
    return true;
}

void process()
{
    //process input
    sort(nums.begin(), nums.end(), srt());
    REP(i, nums.size())
    {
        printf("%d\n", nums[i]);
    }
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
