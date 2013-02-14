#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
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
typedef vector<int> ballot;

vector<ballot> votes;

map<int, int> scores;
vector<string> names;
int n_names;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input

    string name;
    
    scanf("%d ", &n_names);
    REP(iii, n_names)
    {
        getline(cin, name);
        debug(name, endl);
        names.push_back(name);
        scores[names.size()] = 0;
    }

    ballot b;
    int k;
    char line[1000];
    bool cont = true;
    while (cont)
    {
        CL(line, 0);
        fgets(line, 1000, stdin);
        REP(i, n_names)
        {
            if (sscanf(line, "%d ", &k) == -1) { cont = false; break; }
            b.push_back(k);
        }
        debug(line, endl);
        dbg (
             REP(i, b.size())
             {
                 debug(b[i], TAB);
             }
             );
        if (cont) votes.push_back(b);
        b.clear();
    }
    
    return true;
}

void process()
{
    //process input
    int lowest, highest;
    REP(i, n_names)
    {
        lowest = n_names;
        REP(j, votes.size())
        {
            debug(votes[j][0], TAB);
            scores[votes[j][0]]++;
        }
        dbg(cout << endl);
        FOR(k, 1, n_names+1)
        {
            debug(scores[k], endl);
            lowest = min(lowest, scores[k]);
        }
        if (lowest == n_names) break;
        debug(lowest, endl);
        int pos = 0;
        REP(k, n_names)
        {
            if (scores[k] == lowest)
            {
                REP(m, votes.size())
                {
                    if (votes[m][0] == scores[k])
                    {
                        dbg(cout << "wtf" << endl);
                        votes[m].erase(votes[m].begin());
                    }
                }
            }
        }

    }
    highest = 0;
    REP(i, n_names)
    {
        highest = max(highest, scores[i]);
    }
    debug(highest, endl);
    
    REP(i, n_names)
    {
        debug(scores[i], TAB);
        if (scores[i] == highest)
        {
            debug(i, endl);
            cout << names[i] << endl;
        }
    }
}

int main()
{
    int nc = 0;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        names.clear();
        votes.clear();
        scores.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
