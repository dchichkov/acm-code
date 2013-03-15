#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <list>

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
map<int, int> team_members;
list<point> line;
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
    int p_num;
    REP(i, num_teams)
    {
        scanf("%d ", &num_ppl);
        REP(j, num_ppl)
        {
            scanf("%d ", &p_num);
            team_members[p_num] = i;
        }
    }
    
    return true;
}

void process()
{
    //process input
    string input("");
    int p_num;
    list<point>::reverse_iterator pos;
    while (input.compare("STOP") != 0)
    {
        cin >> input;
        if (input.compare("ENQUEUE") == 0)
        {
            cin >> p_num;
            for (pos = line.rbegin(); pos != line.rend(); ++pos)
            {
                if (pos->second == team_members[p_num])
                    break;
            }
            if (pos == line.rend())
            {
                point x;
                x.first = p_num;
                x.second = team_members[p_num];
                line.push_back(x);
            }
            else
            {
                point x;
                x.first = p_num;
                x.second = team_members[p_num];
                line.insert(pos.base(), x);
            }
        }
        else if (input.compare("DEQUEUE") == 0)
        {
            cout << line.front().first << endl;
            line.pop_front();
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
        line.clear();
        team_members.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
