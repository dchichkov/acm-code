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
#define REP(i,n) FOR(i,0,(int)n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int total;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d ", &total);
    if (total == 0) return false;
    return true;
}

void process()
{
    //process input
    double last_five = 0;
    int amt = 0;
    int num_s = 0;
    int a;
    while (amt != total)
    {
        scanf("%d ", &a);
        num_s++;
        amt += a;
        last_five += a;
        if (num_s % 5 == 0)
        {
            printf("%3sTime remaining: ", " ");
            if (last_five == 0)
                printf("stalled");
            else
                /*
                 * yoinked the *0.2 off of the uva forums. alternatively
                 * 5*remaining / last_five has been said to work too
                 */
                printf("%d seconds",  (int)ceil((total-amt) / ((last_five)*0.2)));
            puts("");
            last_five = 0;
        }
    }
    printf("Total time: %d seconds\n\n", num_s);
}

int main()
{
    int casen = 1;
    while (getInput())
    {
        //if (casen != 1) puts("");
        printf("Output for data set %d, %d bytes:\n", casen++, total);
        process();
        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
