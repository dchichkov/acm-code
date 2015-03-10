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
bool flag;
char nwd[50];
unsigned int num;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%s ", nwd);
    debug((int)nwd[0], TAB);     debug((int)nwd[1], endl);
    if (strcmp(nwd, "~") == 0) return false;
    if (strcmp(nwd, "#") == 0)
    {   
        printf("%d\n", num);
        num = 0;
        flag = 0;
    }
    scanf(" ");
    return true;
}

void process()
{
    //process input
    int len = strlen(nwd)-2;
    if (strcmp(nwd, "0") == 0)
        flag = 1;
    else if (strcmp(nwd, "00") == 0)
        flag = 0;
    else
    {
        REP(i, len)
        {
            num <<= 1;
            num += flag;
            debug(i, TAB); debug(strlen(nwd)-2, TAB); debug(num, endl);
        }
    }
    debug(flag , endl);
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
