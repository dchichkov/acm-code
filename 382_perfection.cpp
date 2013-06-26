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
int n;
vector<int> divisors;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d ", &n);
    if (n == 0) return false;
    return true;
}

void process()
{
    //process input
    FOR(i, 2, n)
    {
        if (n % i == 0)
            divisors.push_back(i);
    }
    int x = accumulate(divisors.begin(), divisors.end(), 1);
    printf("%5d  %s\n", n, (n == 1) ? "DEFICIENT" : (n == x) ? "PERFECT" : (n > x) ? "DEFICIENT" : "ABUNDANT");
}

int main()
{
    printf("PERFECTION OUTPUT\n");
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        divisors.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }
    printf("END OF OUTPUT\n");
    return 0;
}
