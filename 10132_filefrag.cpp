#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>

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
vector<string> frags;
int B;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    char line[300];
    while (fgets(line, 300, stdin))
    {
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = 0;
        if (strlen(line) == 0) break;
        debug(line, TAB); debug(B, endl);
        frags.push_back(line);
        B += strlen(line);
        if (feof(stdin)) break;
    }
    B /= (int)frags.size()/2;
    return true;
}

void process()
{
    //process input
    map<string, int> comps;
    REP(i, (int)frags.size())
    {
        REP(j, (int)frags.size())
        {
            if ((frags[i] + frags[j]).length() == B)
                comps[frags[i] + frags[j]]++;
        }
    }

    int mx = 0;
    string final;
    for (map<string, int>::iterator it = comps.begin(); it != comps.end(); ++it)
    {
        if (it->second > mx)
        {
            mx = it->second;
            final = it->first;
        }
    }
    cout << final << endl;
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
        frags.clear();
        B = 0;
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
