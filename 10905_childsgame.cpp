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
vector<string> nums;

struct csrt
{
    bool operator() (const string a, const string b)
    {
        char c[1000];
        char d[1000];
        sprintf(c, "%s", a.data());
        strcat(c, b.c_str());
        sprintf(d, "%s", b.data());
        strcat(d, a.c_str());

        debug(c, TAB); debug(d, endl);
        int l = strlen(c);
        for (int i = 0; i < l; ++i)
        {
            if (c[i] < d[i]) return 0; //RIGHT
            if (c[i] > d[i]) return 1; //LEFT
        }
        return 0;
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

    char fthisprob[1000];
    REP(i, n)
    {
        scanf("%s ", &fthisprob);
        debug(fthisprob, endl);
        nums.push_back(fthisprob);
    }
    return true;
}

void process()
{
    //process input
    sort(nums.begin(), nums.end(), csrt());
    REP(i, nums.size())
    {
        printf("%s", nums[i].c_str());
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
