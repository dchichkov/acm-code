#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <list>
#include <map>

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
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int num_teams;
vector<vi> teams;
vector<vi> teamsiq;
map<int, int> p_team;
list<int> queue;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int num_ppl;
    scanf("%d ", &num_teams);
    if (num_teams == 0) return false;
    teamsiq.resize(num_teams);
    //this is annoying
    int p_num;
    vi team;
    REP(i, num_teams)
    {
        scanf("%d ", &num_ppl);
        teamsiq[i].resize(num_ppl);
        REP(j, num_ppl)
        {
            scanf("%d ", &p_num);
            p_team[i] = p_num;
        }
    }
    
    return true;
}

void process()
{
    //process input
    string input("");
    int p_num;
    int pos = 0, insofar = 0;
    while (input.compare("STOP") != 0)
    {
        cin >> input;
        if (input.compare("ENQUEUE") == 0)
        {
            cin >> p_num;
            REP(i, insofar)
            {
                if (team_members[line[i].first] == team_members[p_num])
                {
                    pos = max(pos, i);
                }
            }
            REP(i, insofar)
            {
                if (line[i].second == pos)
                {
                    line[i].second += 1;
                    break;
                }
            }
            line[p_num].second = pos+1;
            debug(line[p_num].first, TAB); debug(line[p_num].second, endl);
            
        }
        else if (input.compare("DEQUEUE") == 0)
        {

        }
    }
    puts("");
}

int main()
{
    int count = 0;
    while (getInput())
    {
        printf("Scenario #%d\n", ++count);
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        team_members.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
