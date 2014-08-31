#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <numeric>

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
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int n, k;
vi coins;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d %d ", &n, &k);
    coins.resize(n);
    fill(coins.begin(), coins.end(), 0);
    return true;
}

void process()
{
    //process input
    int c, a, x;
    char sign;
    vi left, right;
    REP(i, k)
    {
        scanf("%d ", &c);
        REP(i, c)
        {
            scanf("%d ", &a);
            left.push_back(a);
        }
        REP(i, c)
        {
            scanf("%d ", &a);
            right.push_back(a);
        }

        scanf("%c ", &sign);
        switch (sign)
        {
        case '<':
        case '>':
            REP(i, left.size())
            {
                debug(coins[left[i]-1], TAB);
                coins[left[i]-1] = max(coins[left[i]-1], 0);
            }
            REP(i, right.size())
            {
                debug(coins[right[i]-1], endl);
                coins[right[i]-1] = max(coins[right[i]-1], 0);
            }
            break;
        case '=':
            REP(i, left.size())
            {
                coins[left[i]-1] = coins[right[i]-1] = 1;
            }
            break;
        }
        left.clear();
        right.clear();
    }

    int d = count(coins.begin(), coins.end(), 0);
    debug(d, endl);
    if (d != 1)
    {
        printf("0");
    }
    else
    {
        REP(i, coins.size())
        {
            if (coins[i] == 0)
                printf("%d", i+1);
        }
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
        if (nc != 0) puts("");
        /*CLEAR GLOBAL VARIABLES!*/
        coins.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
