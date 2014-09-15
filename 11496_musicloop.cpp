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
vi samples;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int num_in;
    scanf("%d ", &num_in);
    if (num_in == 0) return false;

    int a;
    REP(i, num_in)
    {
        scanf("%d ", &a);
        samples.push_back(a);
    }
    return true;
}

void process()
{
    //process input
    int total = 0;
    samples.insert(samples.begin(), samples.back());
    samples.push_back(samples[1]);
    int mx = samples[0];
    for (int i = 0; i < samples.size(); ++i)
    {
        if (mx < samples[i])
            mx = samples[i];
        else if (mx > samples[i])
        {
            mx = samples[i];
            total++;
        }
        debug(mx, endl);
    }
    printf("%d\n", total);
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        samples.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
