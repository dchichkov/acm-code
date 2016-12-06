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
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
string line;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int len;
    scanf("%d ", &len);
    if (len == 0) return false;

    getline(cin, line);
    
    return true;
}

void process()
{
    //process input
    int dist=0x0FFFFFFF, x, y = 0;
    if (line.find_first_of("Z", 0) != string::npos)
        dist = 0;
    else
    {
        while (y != string::npos)
        {
            x = line.find_first_of("DR", y);
            y = line.find_first_of("DR", x+1);
            if (line[x] != line[y]) dist = min(dist, abs(x-y));
        }
    }
    printf("%d\n", dist);
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        line.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
