#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <numeric>

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
int qis[100010], pis[100010];
int overhead[100010];
int stations;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d ", &stations);
    int a;

    REP(i, stations)
    {
        scanf("%d ", &a);
        pis[i] = a;
    }
    REP(i, stations)
    {
        scanf("%d ", &a);
        qis[i] = a;
        overhead[i] = pis[i] - qis[i];
    }
    return true;
}

void process()
{
    bool cando = false;
    int n, j, idx;
    //THE MAGIC LINE.
    if (accumulate(pis, pis+stations, 0) < accumulate(qis, qis+stations, 0)) goto done;
    //END THE MAGIC LINE.
    
    FOR(i, 0, stations)
    {
        n = overhead[i];
        if (n < 0) continue;
        for (j = i+1; j != i; j++)
        {
            if (j == stations) {  j = -1; continue; }
            n += overhead[j];
            if (n < 0) break;
        }
        if (j == i)
        {
            cando = true;
            idx = i;
            break;
        }
    }
done:
    if (!cando)
        printf("Not possible");
    else printf("Possible from station %d", idx+1);
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
        CL(qis, 0);
        CL(pis, 0);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
