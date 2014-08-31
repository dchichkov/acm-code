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
vi qis, pis;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int stations;
    scanf("%d ", &stations);
    int a;

    REP(i, stations)
    {
        scanf("%d ", &a);
        pis.push_back(a);
    }
    REP(i, stations)
    {
        scanf("%d ", &a);
        qis.push_back(a);
    }
    return true;
}

void process()
{
    //process input
    int i, j, k;
    bool cando = true;
    for (i = 0; i < pis.size(); ++i)
    {
        if (pis[i] < qis[i]) goto next;
        k = 0;
        for (j = i; j < pis.size()+i; ++j)
        {
            k += pis[j%pis.size()];
            k -= qis[j%pis.size()];
            debug(k, endl);
            if (k < 0) goto next;
        }
        cando = true;
        break;
    next:
        cando = false;
    }

    if (!cando)
        printf("Not possible");
    else printf("Possible from station %d", i+1);
    puts("");
}

int main()
{
    int nc;
    scanf("%d ", &nc);
    int count = 0;
    while (nc-- > 0)
    {
        printf("Case %d: ", ++count);
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        qis.clear();
        pis.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
