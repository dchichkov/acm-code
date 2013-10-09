#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <list>

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
list<int> coins;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int num_coins, coin;
    scanf("%d ", &num_coins);
    REP(i, num_coins)
    {
        scanf("%d ", &coin);
        coins.push_back(coin);
    }
    return true;
}

void process()
{
    //process input
    int left = 0, right = 0;
    coins.sort(std::greater<int>());

    if (coins.size() == 1) printf("%d", coins.front());
    else if (coins.size() == 0) printf("0");
    else
    {
        left = (coins.front());
        debug(left, endl);
        coins.pop_front();
        right = coins.front();
        debug(right, endl);
        coins.pop_front();
        while (!coins.empty())
        {
            if (left > right)
            {
                debug(coins.front(), TAB);
                right += coins.front();
                debug(right, endl);
                coins.pop_front();
            }
            else
            {
                debug(coins.front(), TAB);
                left += (coins.front());
                debug(left, endl);
                coins.pop_front();
            }
            
        }
        debug(left, TAB); debug(right, endl);
        printf("%d", abs(left-right));
    }
    printf("\n");
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
        coins.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
