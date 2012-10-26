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
typedef long long int64; //for clarity
typedef vector<int> vi; //?
typedef vector<point> vp; //?
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } //change min
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } //change max

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
double time_elapsed = 0, time_delta = 0;
int spd = 0;
bool query = false, first_time = true;
double total = 0;
int hr, minu, s;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;

    scanf("%d:%d:%d", &hr, &minu, &s);
    debug(hr, TAB); debug(minu, TAB); debug(s, endl);

    if (!first_time)
        time_delta = (hr*3600 + minu*60 + s) - time_elapsed;
    else
    {
        time_elapsed = (hr*3600 + minu*60 + s);
        first_time = false;
    }
    total += time_delta * spd / 3600;
    debug(time_elapsed, TAB);
    if (cin.peek() == ' ')
    {
        
        scanf("%d", &spd);
        
        query = false;
    }
    else
        query = true;
    debug(spd, endl);
    return true;
}

void process()
{
    //process input
    time_elapsed += time_delta;
    
    debug(total, endl);
    if (query)
    {
        //query
        printf("%02d:%02d:%02d %0.2lf km\n", hr, minu, s, total);
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
