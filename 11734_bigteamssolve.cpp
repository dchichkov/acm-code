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
string l1, l2;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    getline(cin, l1);
    getline(cin, l2);
    return true;
}

void process()
{
    //process input
    bool wa = false;
    bool spcs = false;
    if (l1.length() == l2.length())
    {
        REP(i, l1.length())
        {
            if (l1[i] != l2[i])
            {
                wa = true;
                break;
            }
        }
    }
    else wa = true;

    int m;
    while ((m = l1.find(" ")) != string::npos) l1.erase(m, 1);
    while ((m = l2.find(" ")) != string::npos) l2.erase(m, 1);
    debug(l1, TAB); debug(l2, endl);
    if (l1.length() == l2.length())
    {
        REP(i, l1.length())
        {
            if (l1[i] != l2[i])
            {
                spcs = true;
                break;
            }
        }
    } else spcs = true;
    debug(wa, TAB); debug(spcs, endl);
    if (wa && !spcs)
    {
        printf("Output Format Error");
    }
    else if (wa && spcs)
    {
        printf("Wrong Answer");
    }
    else printf("Yes");

    puts("");
}

int main()
{
    int tc, cnt = 0;
    scanf("%d ", &tc);
    while (tc-- > 0)
    {
        printf("Case %d: ", ++cnt);
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
