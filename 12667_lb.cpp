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
struct last_solved {
    int team;
    int time;
};

bool solved[101][13];
last_solved ls[13];
int n, t, m;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d %d %d ", &n, &t, &m); //num probs, teams, submissions
    return true;
}

void process()
{
    //process input
    char probn, verdict[4];
    int time, tn, pn;
    REP(i, m)
    {
        scanf("%d %d %c %s ", &time, &tn, &probn, verdict);
        pn = probn - 0x41;
        if (strcmp(verdict, "Yes") == 0)
        {
            if (solved[tn][pn] == 0 && ls[pn].time <= time)
            {
                ls[pn].time = time;
                ls[pn].team = tn;
            }
            solved[tn][pn] = 1;
        }
    }

    REP(i, n)
    {
        printf("%c ", 0x41+i);
        if (ls[i].team == 0)
            printf("- -");
        else
            printf("%d %d", ls[i].time, ls[i].team);

        puts("");
    }
}

int main()
{
    //while (getInput())
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
