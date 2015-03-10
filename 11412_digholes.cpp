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
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
vector<char> holes;

/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    return true;
}

void process()
{
    //process input
    vector<char> f, s;
    int fa, fb;
    int sa, sb;
    char c;
    REP(i, 4)
    {
        scanf("%c", &c);
        debug(c, endl);
        f.push_back(c);
    }
    scanf("%d %d ", &fa, &fb);
    REP(i, 4)
    {
        scanf("%c", &c);
        debug(c, endl);
        s.push_back(c);
    }
    scanf("%d %d ", &sa, &sb);
    
    bool match;
    int cnta, cntb, cntc, cntd;
    vector<char>::iterator it;

    //debug(fa, TAB); debug(fb, TAB); debug(sa, TAB); debug(sb, endl);
    do
    {
        match = true;
        cnta = cntb = cntc = cntd = 0;
        dbg (
            REP(i, 4)
            {
                printf("%c ", holes[i]);
            }
            puts("");
            );
        REP(i, 4)
        {
            if ((it = find(holes.begin(), holes.begin()+4, f[i])) != holes.begin()+4)
            {
                debug(i, TAB); debug(it-holes.begin(), endl);
                if (it-holes.begin() == i) cnta++;
                else cntb++;
            }
            if ((it = find(holes.begin(), holes.begin()+4, s[i])) != holes.begin()+4)
            {
                if (it-holes.begin() == i) cntc++;
                else cntd++;
            }
        }
        if (!(cnta == fa && cntb == fb && cntc == sa && cntd == sb))
            match = false;
        debug(cnta, TAB); debug(fa, endl);
        debug(cntb, TAB); debug(fb, endl);
        debug(cntc, TAB); debug(sa, endl);
        debug(cntd, TAB); debug(sb, endl);
        if (match) break;
    } while (next_permutation(holes.begin(), holes.end()));
    printf("%s\n", match ? "Possible" : "Cheat");
}

int main()
{
    holes.push_back('B');
    holes.push_back('G');
    holes.push_back('O');
    holes.push_back('R');
    holes.push_back('V');
    holes.push_back('Y');

    int tc;
    scanf("%d ", &tc);
    while (tc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
