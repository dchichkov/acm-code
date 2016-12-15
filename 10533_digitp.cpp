#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <bitset>

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
#define REP(i,n) FOR(i,0,(int)n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
const int MX = 1000000+5;
bitset<MX> bs;

int a, b;
int rt[MX];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d %d ", &a, &b);
    return true;
}

bool digitp(int p)
{
    int x = 0;
    while (p != 0)
    {
        x += p%10;
        p /= 10;
    }

    return bs[x] == 0;
}

void process()
{
    //process input
    debug(rt[b], TAB); debug(rt[a], endl);
    printf("%d\n", rt[b]-rt[a-1]);
}

int main()
{
    bs[0] = 1;
    bs[1] = 1;
    for (long long i = 2; i < MX; ++i)
    {
        if (bs[i] == 0)
        {
            for (long long j = i*i; j < MX; j +=i)
                bs[j] = 1;
        }
    }


    int total = 0;
    FOR(i, 2, 1000001)
    {
        if (digitp(i) && bs[i] == 0)
        {
            ++total;
        }
        rt[i] = total;
    }
    

    int nc;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
