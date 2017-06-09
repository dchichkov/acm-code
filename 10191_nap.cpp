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
#define REP(i,n) FOR(i,0,(int)n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
struct time_interval {
    int time1, time2;
};
vector<time_interval> schedule;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int s;
    char eol[300]; //none longer than 255
    scanf("%d ", &s);
    if (feof(stdin)) return false;
    int h, m;
    int h2, m2;
    time_interval ti;
    REP(i, s)
    {
        fgets(eol, 300, stdin);
        sscanf(eol, "%d:%d %d:%d ", &h, &m, &h2, &m2);
        ti.time1 = (h*60+m);
        ti.time2 = (h2*60+m2);
        schedule.push_back(ti);
    }
    return true;
}

void process()
{
    //process input
    sort(schedule.begin(), schedule.end(), [](const time_interval& a,
                                              const time_interval& b)
         {
             return a.time1 < b.time1;
         });
    int starts = (10*60); //10:00
    int how_long = schedule[0].time1 - starts;
    FOR(i, 1, schedule.size())
    {
        if ((schedule[i].time1 - schedule[i-1].time2) > how_long)
        {
            starts = schedule[i-1].time2;
            how_long = schedule[i].time1 - schedule[i-1].time2;
        }
    }
    //debug(schedule.back().time2, TAB);
    if (((18*60) /*18:00*/ - schedule.back().time2) > how_long)
    {
        starts = schedule.back().time2;
        how_long = (18*60) - schedule.back().time2;
        //debug(starts, TAB); debug(how_long, endl);
    }
    printf("the longest nap starts at %02d:%02d and will last for ", starts/60,
           (starts - ((starts/60))*60));
    int hours = how_long / 60;
    if (hours > 0)
        printf("%d hours and ", hours);
    int minutes = how_long - (hours*60);
    printf("%d minutes.\n", minutes);
}

int main()
{
    int cn = 1;
    while (getInput())
    {
        printf("Day #%d: ", cn++);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        schedule.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
