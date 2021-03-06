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
typedef unsigned long long ull;
int cents;
ull ways[6][30010];
int coins[] = {50, 25, 10, 5, 1};
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

ull make_change(int type, int val)
{
    if (val == 0)
        return 1;
    if (val < 0 || type == 5)
        return 0;
    if (ways[type][val] != -1) return ways[type][val];
    return ways[type][val] = make_change(type+1, val) + //if we ignore the coin
        make_change(type, val - coins[type]); //if we use the coin
}

void process()
{
    //process input
    if (make_change(0, cents) == 1)
        printf("There is only 1 way to produce %d cents change.", cents);
    else
        printf("There are %llu ways to produce %d cents change.",
               make_change(0, cents),
               cents);

    puts("");
}

int main()
{
    CL2d(ways, -1, 6, 30010);
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
