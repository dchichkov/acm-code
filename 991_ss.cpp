#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

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
int ppl[20];
int num;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    scanf("%d ", &num);
    return true;
}

long long fact(long long x)
{
    return x == 1 ? x : x * fact(x-1);
}

void process()
{
    //process input
    printf("%d", (int)ppl[num]);
}

int main()
{
    CL(ppl, 0);
    ppl[0] = 1;
    FOR(i, 0, 19)
    {
        ppl[i+1] = ((2*(2*(i)+1) * ppl[i]) / ((i)+2));
        debug(ppl[i], endl);
    }
    
    while (getInput())
    {

        process();
        /*CLEAR GLOBAL VARIABLES!*/
        puts("");
        if (!feof(stdin)) puts("");
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
