#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <numeric>

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
vi dists;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int ndists, dist;
    scanf("%d ", &ndists);
    REP(i, ndists)
    {
        scanf("%d ", &dist);
        dists.push_back(dist);
    }
    return true;
}

void process()
{
    //process input
    int min = *(min_element(dists.begin(), dists.end()));
    int max = *(max_element(dists.begin(), dists.end()));

    printf("%d\n", (max-min)*2);
}

int main()
{
    int nc;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        dists.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
