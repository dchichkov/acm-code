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
const int MAX_PRIME = 100010041;
int a, b;
bool soe[MAX_PRIME];
int eoe[10002];
/*global variables*/

void dump()
{
    //dump data
}

void sieve()
{
    CL(soe, 1);
    for (int i = 41; i < MAX_PRIME/2; ++i)
    {
        if (soe[i])
        {
            for (int j = i+i; j < MAX_PRIME; j += i )
            {
                soe[j] = 0;
            }
        }
    }

    REP(i, 10002)
    {

        eoe[i] = (i*i) + i + 41;
    }

}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;

    scanf("%d %d ", &a, &b);
    return true;
}

void process()
{
    //process input
    int total = (b+1)-a;
    int right = 0;

    for (int i = a; i <= b; ++i)
    {
        debug(i, TAB);
        debug(eoe[i], TAB);
        debug(soe[eoe[i]], endl);
        if (soe[eoe[i]])
            right++;
    }

    printf("%01.02lf\n",(round(((double)right/total)*10000))/100);
}

int main()
{
    sieve();
    dbg(for (int i = 0; i < MAX_PRIME; ++i)
        printf("%d", soe[i]);
        printf("\n"));
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
