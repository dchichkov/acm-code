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
vi heights;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int n, a;
    scanf("%d ", &n);
    REP(i, n)
    {
        scanf("%d ", &a);
        heights.push_back(a);
    }
    return true;
}

void bin_search(int n)
{
    int low = 0, high = heights.size(), low2 = 0, high2 = 0;
    int mid;
    while (high > low)
    {
        mid = (high+low)/2;
        if (heights[mid] < n) low = mid+1;
        else  high = mid;
    }

    for (low2 = min(low, (int)heights.size()-1);  low2 >= 0; low2--)
        if (heights[low2] < n)
            break;

    for (high2 = high; high2 < heights.size(); ++high2)
        if (heights[high2] > n)
            break;

    debug(low2, TAB); debug(high2, endl);
    if (low2 != -1)
        printf("%d ", heights[low2]);
    else
        printf("X ");

    if (high2 != heights.size())
        printf("%d", heights[high2]);
    else
        printf("X");

}

void process()
{
    //process input
    int q, a;
    
    scanf("%d ", &q);
    REP(i, q)
    {
        scanf("%d ", &a);
        bin_search(a);
        puts("");
    }
}

int main()
{
    //while ()
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
