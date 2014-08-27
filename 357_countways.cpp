#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>

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
int cents;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    scanf("%d ", &cents);
    return true;
}

void process()
{
    //process input
    if (cents < 5) printf("There is only 1 way to produce %d cents change.", cents);
    else
    {
        int tmp = cents;
        int h, q, d, n;
        h = q = d = n = 0;
        while (tmp > 50)
        {
            tmp -= 50;
            h++;
        }
        while (tmp > 25)
        {
            tmp -= 25;
            q++;
        }
        while (tmp > 10)
        {
            tmp -= 10;
            d++;
        }
        while (tmp > 5)
        {
            tmp -= 5;
            n++;
        }

        printf("There are %d ways to produce %d cents change.", h*16+q*8+d*4+n*2, cents);
    }
    puts("");
    
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
