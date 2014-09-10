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
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int d;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    char ft[30];
    fgets(ft, 30, stdin);
    if (ft[0] == '-') return false;

    if (ft[1] == 'x')
    {
        sscanf(ft, "%x", &d);
        printf("%d\n", d);
    }
    else
    {
        sscanf(ft, "%d", &d);
        printf("0x%X\n", d);
    }
        
        
    return true;
}

void process()
{
    //process input
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
