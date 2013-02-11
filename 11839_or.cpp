#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <map>
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

int num_in;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d ", &num_in);
    if (num_in == 0) return false;
    return true;
}

void process()
{

    int n[5];
    int c, x;
    //process input
    REP(i, num_in)
    {
        c = x = 0;
        REP(j, 5)
        {
            scanf("%d ", &n[j]);
            if (n[j] <= 127)
            {
                x = j;
                c++;
            }
        }
        if (c == 1)
            printf("%c", 'A'+x);
        else
            printf("*");
        
        debug(c, TAB); debug(d, TAB); debug(x, TAB); debug(y, endl);
        
        printf("\n");
    }
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
