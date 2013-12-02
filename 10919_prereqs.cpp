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
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int num_courses, num_cates;
vector<string> selected;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d ", &num_courses);
    if (num_courses == 0) return false;
    scanf("%d ", &num_cates);
    debug(num_courses, TAB); debug(num_cates, endl);
    return true;
}

void process()
{
    //process input
    char cnum[5];
    REP(i, num_courses)
    {
        scanf("%4s ", cnum);
        selected.push_back(cnum);
        debug(cnum, TAB);
    }
    dbg(cout << endl);

    int numc, numneeded;
    bool cando = true;
    REP(i, num_cates)
    {
        scanf("%d %d ", &numc, &numneeded);
        debug(numc, TAB); debug(numneeded, endl);
        REP(j, numc)
        {
            scanf("%4s ", cnum);
            debug(cnum, TAB);
            if (find(selected.begin(), selected.end(), cnum) != selected.end())
                numneeded--;
        }
        dbg(cout << endl);
        if (numneeded > 0)
            cando = false;
    }
    printf("%s\n", cando ? "yes" : "no");
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        selected.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
