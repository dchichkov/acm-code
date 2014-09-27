#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <limits>

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
struct triple
{
    int first;
    int second;
    int third;
};
typedef vector<triple> vt;
vt elephants;

struct srt
{
    bool operator() (const triple& a, const triple& b)
    {
        return a.second > b.second;
    }
};

struct srt2
{
    bool operator() (const triple& a, const triple& b)
    {
        return a.first > b.first;
    }
};
/*global variables*/

void dump()
{
    //dump data
    REP(i, (int)elephants.size())
    {
        debug(elephants[i].first, TAB);
        debug(elephants[i].second, TAB);
        debug(elephants[i].third, endl);
    }
}

bool getInput()
{
    //get input

    triple elephant;
    int weight, iq;
    int i = 1;
    while (scanf("%d %d ", &weight, &iq) != EOF)
    {
        elephant.first = weight;
        elephant.second = (iq);
        elephant.third = i;
        elephants.push_back(elephant);
        ++i;
    }
    return true;
}


void process()
{
    //process input
    sort(elephants.begin(), elephants.end(), srt());
    dbg( dump(); );

    vi LIS;
    LIS.push_back(1);
    int j = 0, mx, dif = 0;
    vi BACK;
    FOR(i, 1, (int)elephants.size())
    {
        mx = 1;
        for (j = i-1; j >= 0; --j)
        {
            if (elephants[j].first < elephants[i].first)
            {
                mx = max(LIS[j]+1, mx);
            }
        }
        LIS.push_back(mx);
        if (dif < LIS[i])
        {
            BACK.push_back(elephants[i].third);
            dif = LIS[i];
        }
    }

    dbg (
    REP(i, LIS.size())
        printf("%d ", LIS[i]);
    puts("");

    debug(BACK.size(), endl);
    REP(i, BACK.size())
    {
        printf("%d %d %d\n", elephants[BACK[i]].first,
               elephants[BACK[i]].second,
               BACK[i]);
    }
    puts("");
        );

    printf("%d\n", (int)BACK.size());
    REP(i, BACK.size())
        printf("%d\n", BACK[i]);

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
