#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <numeric>
#include <list>

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
#define REP(i,n) FOR(i,0,(int)n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
vector<vi> stations;
list<int> specimens;
int c, s;
double AM;

/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    scanf("%d %d ", &c, &s);
    stations.resize(c);
    int a;
    REP(i, ((2*c)-s))
    {
        specimens.push_back(0);
    }
    vi mm;
    REP(i, s)
    {
        scanf("%d ", &a);
        mm.push_back(a);
    }
    SORT(mm);
    REP(i, mm.size())
    {
        specimens.push_back(mm[i]);
    }
    AM = (double)accumulate(specimens.begin(), specimens.end(), 0) / (c*1.0);

    return true;
}

void process()
{
    //process input
    int pos = 0;
    debug(stations.size(), endl);
    while (!specimens.empty())
    {
        debug(pos, endl);
        stations[pos].push_back(specimens.front());
        stations[pos].push_back(specimens.back());
        specimens.pop_front();
        specimens.pop_back();
        ++pos;
    }
    double ttl = 0;
    REP(i, stations.size())
    {
        ttl += fabs(AM-accumulate(stations[i].begin(), stations[i].end(), 0));
    }

    REP(i, stations.size())
    {
        printf(" %d:", i);
        REP(j, stations[i].size())
        {
            if (stations[i][j] == 0) continue;
            printf(" %d", stations[i][j]);
        }
        puts("");
    }
    printf("IMBALANCE = %0.5lf\n", ttl);
}

int main()
{
    int cnt = 1;
    while (getInput())
    {
        printf("Set #%d\n", cnt++);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        stations.clear();
        /*CLEAR GLOBAL VARIABLES!*/
        puts("");
    }

    return 0;
}
