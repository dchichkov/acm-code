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
vp elephants;

struct srt_by_second
{
    bool operator() (const point& a, const point& b)
    {
        return a.second > b.second;
    }
};
/*global variables*/

void dump()
{
    //dump data
    REP(i, (int)elephants.size())
    {
        debug(elephants[i].first, TAB); debug(elephants[i].second, endl);
    }
}

bool getInput()
{
    //get input

    point elephant;
    int weight, iq;
    while (scanf("%d %d ", &weight, &iq) != EOF)
    {
        elephant.first = weight;
        elephant.second = iq;
        debug(weight, TAB); debug(iq, endl);
        elephants.push_back(elephant);
    }
    return true;
}


void process()
{
    //process input
    sort(elephants.begin(), elephants.end(), srt_by_second());
    dbg( dump(); );

    vi LIS;
    LIS.push_back(1);
    int j = 0, mx = 1;
    FOR(i, 1, (int)elephants.size())
    {
        for (;j < i; ++j)
        {
            if (elephants[j].first < elephants[i].first)
            {
                mx = max(j+1, mx);
            }
        }
        LIS.push_back(mx);
    }

    int cntr = LIS[LIS.size()-1];
    dbg(
        REP(i, LIS.size())
        {
            printf("%d ", LIS[i]);
        }
        puts("");
        );
    printf("%d\n", cntr);
    for (int i = LIS.size()-1; i >= 0; --i)
    {
        if (LIS[i] == cntr)
        {
            printf("%d\n", i+1);
            --cntr;
        }
    }
}

int main()
{
//    while ()
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
