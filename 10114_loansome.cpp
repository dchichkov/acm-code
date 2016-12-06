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
int mnths;
double dp;
double rates[100];
double loan;
#define EPS 1e-9
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d %lf %lf ", &mnths, &dp, &loan);
    if (mnths < 0) return false;
    return true;
}

void process()
{
    //process input
    int nr, mnth;
    double rate;
    scanf("%d ", &nr);
    REP(i, nr)
    {
        scanf("%d %lf ", &mnth, &rate);
        rates[mnth] = rate;
    }
    
    int nm = 0;
    double cv = (loan + dp);
    double pay = (loan / (1.0*mnths));
    mnth = 0;
    rate = rates[mnth++];
    cv -= (rate * cv);
    debug(rate, TAB); debug(cv, TAB); debug(loan, endl);
    while (cv < loan && mnth != 101)
    {
        if (fabs(rates[mnth]-0) > EPS)
            rate = rates[mnth];
        cv -= (rate * cv);
        nm++;
        mnth++;
        loan -= pay;
        debug(rate, TAB); debug(cv, TAB); debug(loan, endl);
    }
    printf("%d month%s\n", nm, nm != 1 ? "s" : "");
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        CL(rates, 0);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
