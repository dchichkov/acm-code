#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

#define DEBUG  //comment this line to pull out print statements
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
int amt;
bool valid[10001];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    double in;
    scanf("%lf ", &in);
    amt = in*100;
    if (amt == 0) return false;
    return true;
}

void process()
{
    //process input
    vector<int> coins;
    int nt = amt, nz = 0;
    while (nt != 0)
    {
        nz++;
        nt -= 5;
    }
    coins.push_back(amt);
    while (coins.size() != nz)
    {
        //combine
        for (int i = 0; i < coins.size(); ++i)
        {
            nt++;
            
        }

    }
    char a[20], b[20];
    sprintf(a, "%.2lf", ((double)amt/100));
    sprintf(b, "%d", nt);
    printf("%6s%17s", a, b);
}

int main()
{
    valid[10000] = 1;
    valid[5000] = 1;
    valid[2000] = 1;
    valid[1000] = 1;
    valid[200] = 1;
    valid[100] = 1;
    valid[50] = 1;
    valid[20] = 1;
    valid[10] = 1;
    valid[5] = 1;
    
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
