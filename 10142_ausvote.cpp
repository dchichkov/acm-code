#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

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

#define TAB '\t'
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
vector<string> candidates;

vector<vector<int> > voters;
/*global variables*/

void dump()
{
    //dump data
    REP(i, candidates.size())
    {
        debug(candidates[i], endl);
    }

    REP(i, voters.size())
    {
        debug(voters[i].size(), TAB);
        REP(j, voters[i].size())
        {
            dbg ( cout << voters[i][j] << " "; );
        }
        dbg (cout << endl; );
    }
}

bool getInput()
{
    //get input
    int nc;
    scanf("%d ", &nc);

    char line[1000];
    REP(i, nc)
    {
        fgets(line, 1000, stdin);
        line[strlen(line)-1] = 0;
        candidates.push_back(line);
    }

    vector<int> ballot(nc, 0);
    fgets(line, 1000, stdin);
    int vote, i;
    while (line[0] != '\n' && !feof(stdin) && line[0] != 0)
    {
        char* token = strtok(line, " ");
        i = 0;
        while (token != NULL)
        {
            sscanf(token, "%d ", &vote);
            ballot[i] = vote;
            ++i;
            token = strtok(NULL, " ");
        }
        reverse(ballot.begin(), ballot.end());
        voters.push_back(ballot);
        line[0] = 0;
        fgets(line, 1000, stdin);
    }
    dump();
    return true;
}

void process()
{
    //process input
    vector<int> cvote(candidates.size()+1, 0);
    int pos;
    string winname;
    bool tied;
    
    while (true)
    {
        winname.clear();
        tied = false;
        REP(i, voters.size())
        {
            while (cvote[voters[i].back()] == -1)
                voters[i].pop_back();
            cvote[voters[i].back()]++;
        }

        FOR(i, 1, cvote.size())
        {
            debug(cvote[i], TAB); debug(candidates[i-1], endl);
            if (cvote[i] > int(voters.size())/2)
            {
                debug(cvote[i], TAB); debug(int(voters.size())/2, endl);
                winname = candidates[i-1];
                //goto done;
            }

        }
        if (!winname.empty())
            goto done;

        //find lowest
        int lowest = *(max_element(cvote.begin(), cvote.end()));
        int pos = -1;
        FOR(i, 1, cvote.size())
        {
            if (cvote[i] < lowest && cvote[i] > -1)
            {
                lowest = cvote[i];
                pos = i;
            }
        }
        
        debug(lowest, TAB); debug(pos, endl);
        if (pos == -1)
        {
            tied = true;
            goto done;
        }

        FOR(i, 1, cvote.size())
        {
            debug(cvote[i], endl);
            if (cvote[i] == lowest) cvote[i] = -1;
        }

        FOR(i, 1, cvote.size())
        {
            if (cvote[i] > 0) cvote[i] = 0;
        }
    }
done:
    if (tied)
    {
        REP(i, candidates.size())
        {
            if (cvote[i+1] != -1)
            {
                printf("%s\n", candidates[i].c_str());
            }
        }
    }
    else
    {
        printf("%s\n", winname.c_str());
    }
}

int main()
{
    int nc;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        candidates.clear();
        voters.clear();
        /*CLEAR GLOBAL VARIABLES!*/

        if (nc != 0) puts("");
    }

    return 0;
}
