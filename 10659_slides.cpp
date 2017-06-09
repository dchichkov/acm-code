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
vector<string> lines;
int slideh, slidew;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int paragraphs;
    scanf("%d ", &paragraphs);
    char line[1000];
    REP(i, paragraphs)
    {
        fgets(line, 1000, stdin);
        line[strlen(line)-1] = 0; //remove the end of line new line;
        lines.push_back(line);
    }

    scanf("%d %d ", &slidew, &slideh);
    return true;
}

bool fit(string s, int& remh, int fac)
{
    //make fit
    int spos = -1;
    
    vector<string> boundaries;
    boundaries.push_back(s);

    int swidth = boundaries[0].length() * fac;
    debug(boundaries[0].length(), endl);
    
    string t;
    debug(swidth, TAB);
    if (swidth > slidew)
    {
        debug(fac, TAB);
        debug(swidth, TAB);

        REP(i, boundaries.size())
        {
            t.clear();
            debug(boundaries[i], endl);
            while (boundaries[i].length() * fac > slidew)
            {
                if (!t.empty()) t.insert(0, " ");
                spos = boundaries[i].rfind(" ");
                if (spos == string::npos) spos = -1;
                t.insert(0, boundaries[i].substr(spos+1, boundaries[i].length()-spos));
                boundaries[i].erase(max(spos, 0), boundaries[i].length()-spos);
                debug(boundaries[i].length(), endl);
                
            }
            if (boundaries[i].empty()) return false;

            if (!t.empty())
            {
                debug(t, endl);
                if (i+1 == boundaries.size()) boundaries.push_back(t);
                else
                {
                    t += " ";
                    boundaries[i+1].insert(0, t);
                }
            }
        }
    }

    remh -= (boundaries.size() * fac);
    if (remh < 0) return false;
    else return true;

}

void process()
{
    //process input

    bool cando;
    int i;
    int remh;

    for (i = 28; i > 7; --i)
    {
        remh = slideh;
        cando = true;
        REP(j, lines.size())
        {
            cando = fit(lines[j], remh, i);
            if (!cando) break;
        }

        if (cando) break;
    }
    cando ? printf("%d", i) : printf("%s", "No solution");
    puts("");
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
        lines.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
