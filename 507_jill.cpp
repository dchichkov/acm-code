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
int c, n;
/*global variables*/

void dump()
{
    //dump data

}

bool getInput()
{
    //get input
    scanf("%d ", &n);
    return true;
}

void process()
{
    c++;
    //process input

    int t, k = 0, l = 0, j = 0;
    int meh = 0, msf = 0;
    vector<int> v;
    REP(i, n-1)
    {
        scanf("%d ", &t);
        v.push_back(t);
    }

    REP(i, v.size())
    {
        debug(v[i], endl);
        meh = meh + v[i];
        if (meh >= msf)
        {
            k = j;
            l = i;
            msf = meh;
            
        }
        else if (meh < 0)
        {
            meh = 0;
            j = i+1;
        }
        //msf = max(msf, meh);
        debug(meh, TAB); debug(msf, endl);
    }
    debug(k, TAB); debug(l, endl);

    /*int w = 0;
    debug(k, TAB); debug(l, endl);
    FOR(i, k, l)
    {
        w += v[i];
    }*/
    if (msf != 0)
        printf("The nicest part of route %d is between stops %d and %d", c, k+1, l+2);
    else
        printf("Route %d has no nice parts", c);
    printf("\n");
        
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

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
