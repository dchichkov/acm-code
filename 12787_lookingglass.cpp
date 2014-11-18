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
char num[20];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    fgets(num, 20, stdin);
    if (strlen(num) == 1) return false;
    num[strlen(num)-1] = 0;
    debug(num, endl);
    return true;
}

bool ispalindrome(long n)
{
    if (n == 0) return false;
    char str[20];
    debug(n, TAB);
    sprintf(str, "%ld", n);
    bool chk = true;
    debug(str, endl);
    REP(i, strlen(str)-1)
    {
        if (str[i] != str[strlen(str)-i-1])
        {
            chk = false;
            break;
        }
    }

    return chk;
}

void process()
{
    //process input
    bool chk = false;
    int i = 2;
    for(; i < 100; ++i)
    {
        debug(strtol(num, NULL, i), endl);
        if ((chk = ispalindrome(strtol(num, NULL, i))))
            break;
    }
    
    printf("%d\n", chk ? i : 0);
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
