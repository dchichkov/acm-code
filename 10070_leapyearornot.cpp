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
unsigned long long year;
bool first_time = true;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    else
    {
        if (first_time)
        {
            first_time = false;
        }
        else puts("");
    }
    scanf("%lld ", &year);
    return true;
}

bool isleapyear()
{
    if ((year % 4 == 0 && year % 100 != 0) ||
        (year % 400 == 0))
        return true;
    return false;
}

bool ishuluculu()
{
    if (year % 15 == 0) return true;
    return false;
}

bool isbulukulu()
{
    if (year % 55 == 0) return true;
    return false;
}

void process()
{
    //process input
    if (isleapyear())
        puts("This is leap year.");
    if (ishuluculu())
        puts("This is huluculu festival year.");
    if (isbulukulu())
        puts("This is bulukulu festival year.");
    if (!isleapyear() && !ishuluculu() && !isbulukulu())
        puts("This is an ordinary year.");
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
