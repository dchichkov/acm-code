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
int stations;
vi st;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d ", &stations);
    if (stations == 0) return false;
    int a;
    
    REP(i, stations)
    {
        scanf("%d ", &a);
        st.push_back(a);
    }
    return true;
}

void process()
{
    //process input
    bool pos = true;
    SORT(st);
    FOR(i, 1, st.size())
    {
        if (abs(st[i-1] - st[i]) > 200)
            pos = false;
    }
    if ((1422 - st.back())*2 > 200) pos = false;
    
    printf("%s\n", pos ? "POSSIBLE" : "IMPOSSIBLE");
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        st.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
