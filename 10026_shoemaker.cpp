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
struct job
{
    int position;
    double penalty;
    double days;
};
vector<job> jobs;
/*global variables*/

struct srt
{
    bool operator()(const job& a, const job& b)
    {
        return (a.days/a.penalty) < (b.days/b.penalty);
    }
};

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    job j;
    int n;
    scanf("%d ", &n);
    REP(i, n)
    {
        scanf("%lf %lf ", &j.days, &j.penalty);
        j.position = i+1;
        jobs.push_back(j);
    }
    return true;
}

void process()
{
    //process input
    stable_sort(jobs.begin(), jobs.end(), srt());
    printf("%d", jobs[0].position);
    FOR(i, 1, jobs.size())
    {
        printf(" %d", jobs[i].position);
    }
    puts("");
}

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc-- > 0)
    {
        getInput();
        process();
        if (tc != 0) puts("");
        /*CLEAR GLOBAL VARIABLES!*/
        jobs.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
