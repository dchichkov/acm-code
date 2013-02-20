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
double cards[10000];
int n;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
  if (foeof(stdin)) return false;
  scanf("%d ", &n);
    return true;
}

void process()
{
    //process input
  printf("%5d%5c%0.3llf\n", n, ' ', cards[n]);
}

int main()
{
  printf("# Cards Overhang\n");
  cards[0] = 0;
  cards[1] = 0.5;
  FOR(i, 2, 100000)
    {
      cards[i] = cards[i-1] + ((double)1/i*2);
    }

    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
