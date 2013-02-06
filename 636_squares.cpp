#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

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
char num[10];
long long int numb;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    numb = 0;
    //get input
    fgets(num, 10, stdin);
    num[strlen(num)-1] = 0;
    sscanf(num, "%lld", &numb);
    debug(numb, endl);
    
    if (numb == 0) return false;
    return true;
}

void process()
{
    //process input
    double rt;
    int highest = 0;
    REP(i, strlen(num))
        highest = max(highest, num[0]-0x30);
    debug(highest, endl);
    FOR(i, highest+1, 100)
    {
        numb = strtoll(num, NULL, i);
        rt = sqrt(numb);
        //debug(rt, endl);
        if ((long long)ceil(rt) == (long long)floor(rt))
        {
            cout << i << endl;
            break;
        }
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
