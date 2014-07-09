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
vi floors;
const int signb = 1 << 31;
/*global variables*/

struct sort_abs
{
    bool operator()(const int& a, const int& b)
    {
        return abs(a) < abs(b);
    }
};

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int num_in, a;
    scanf("%d ", &num_in);
    REP(i, num_in)
    {
        scanf("%d ", &a);
        floors.push_back(a);
    }
    return true;
}

void process()
{
    //process input
    sort(floors.begin(), floors.end(), sort_abs());
    reverse(floors.begin(), floors.end());

    if (floors.size() == 0) printf("0");
    else
    {
        int count = 1;
        REP(i, (int)floors.size()-1)
        {
            if ((floors[i]&signb) != (floors[i+1]&signb)) ++count;
        }
        printf("%d", count);
    }
    puts("");
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
        floors.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
