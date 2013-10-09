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
struct tlight
{
    int r, g, y;
    int cur;
};

vector<tlight> lights;
const int MAX_TIME = 3600 * 5; //1 hr = 60min*60sec, times 5 for 5 hours
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int temp = -1, temp2 = -1;
    tlight tl;

    //at least two
    scanf("%d %d ", &temp, &temp2);

    if (temp == 0 && temp2 == 0)
        return false;

    tl.r = temp;
    tl.g = temp-5;
    tl.y = 5;
    lights.push_back(tl);

    tl.r = temp2;
    tl.g = temp2-5;
    tl.y = 5;
    lights.push_back(tl);

    while (true)
    {
        scanf("%d ", &temp);
        if (temp == 0) break;
        tl.r = temp;
        tl.g = temp-5;
        tl.y = 5;
        lights.push_back(tl);
    }
    
    return true;
}

void process()
{
    //process input
    int seconds = 0;
    for (vector<tlight>::iterator it = lights.begin(); it != lights.end(); ++it)
    {
        seconds = max(seconds, it->r);
    }
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        lights.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
