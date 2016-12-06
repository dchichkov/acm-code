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
string ccnum;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    getline(cin, ccnum);
    return true;
}

void process()
{
    //process input
    REP(i, ccnum.length())
    {
        if (ccnum[i] == ' ')
        {
            ccnum.erase(i, 1);
            --i;
        }
    }
    debug(ccnum, endl);
    
    int total = 0;
    int tmp;
    bool tog = 1;
    REP(i, ccnum.length())
    {
        tog = 1 - tog;
        tmp = ccnum[i] - '0';
        if (tog)
            total += tmp;
        else
        {
            tmp *= 2;
            if (tmp > 9)
            {
                total += tmp / 10;
                total += tmp % 10;
            }
            else
                total += tmp;
        }
    }

    if ((total) % 10 == 0)
        printf("Valid");
    else
        printf("Invalid");

    puts("");
}

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
