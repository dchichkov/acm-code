#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
#include <numeric>

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
struct team
{
    int team_num;
    int probs[10];
    int total_time;
};

vector<team> teams;
set<int> ateams;

struct team_sort
{
    bool operator() (const team& a, const team& b)
    {
        int c = accumulate(a.probs, a.probs+10, 0);
        int d = accumulate(b.probs, b.probs+10, 0);
        if (c == d)
            return a.total_time < b.total_time;
        else
            return c > d;
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

    if (feof(stdin)) return false;

    char line[80];
    int teamnum, probnum, time;
    char subc;
    while(fgets(line, 80, stdin), (strlen(line) != 1))
    {
        sscanf(line, "%d %d %d %c ", &teamnum, &probnum, &time, &subc);
        debug(teamnum, TAB); debug(probnum, TAB); debug(time, TAB); debug(subc, endl);
        teams[teamnum].team_num = teamnum;
        ateams.insert(teamnum);
        switch (subc)
        {
        case 'I':
            if (teams[teamnum].probs[probnum] != 1)
                teams[teamnum].total_time += 20;
            break;
        case 'C':
            if (teams[teamnum].probs[probnum] != 1)
            {
                teams[teamnum].probs[probnum] = 1;
                teams[teamnum].total_time += time;
            }
            break;
        }
        if (feof(stdin)) break;
    }
    return true;
}

void process()
{
    //process input
    vector<team> vt;
    for (set<int>::iterator it = ateams.begin(); it != ateams.end(); ++it)
    {
        vt.push_back(teams[*it]);
    }

    sort(vt.begin(), vt.end(), team_sort());
    int f;
    REP(i, vt.size())
    {
        f = accumulate(vt[i].probs, vt[i].probs+10, 0);
        printf("%d %d %d\n", vt[i].team_num, f, vt[i].total_time);
    }

}

int main()
{
    teams.reserve(101);
    int nc;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();
        if (nc > 0) puts("");
        /*CLEAR GLOBAL VARIABLES!*/
        teams.clear();
        ateams.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
