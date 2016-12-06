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
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
const int MAX = 1000;
int a, b;
vi plist;
bitset<MAX> bs;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    scanf("%d %d ", &a, &b);
    return true;
}

void process()
{
    //process input
    vi::iterator it = upper_bound(plist.begin(), plist.end(), a);
    int cnt;
    cnt = it - plist.begin();
    debug(cnt, endl);
    printf("%d %d:", a, b);
    if (cnt % 2 == 0)
    {
        for (int i = 0-min((cnt+1)/2, b); i < b
                 && plist[cnt/2+i] <= a
                 && cnt/2+i < plist.size(); ++i)
        {
            printf(" %d", plist[cnt/2+i]);
        }
    }
    else
    {
        for (int i = 0-min((cnt+1)/2, b)+1; i < b
                 && plist[cnt/2+i] <= a
                 && cnt/2+i < plist.size(); ++i)
        {
            printf(" %d", plist[cnt/2+i]);
        }
    }
    puts("\n");
}

int main()
{
    //sieve
    bs.reset();
    bs[0] = 1;
    bs[1] = 1;
    plist.push_back(1);
    FOR(i, 2, MAX+1)
    {
        if (!bs[i])
        {
            plist.push_back(i);
            for (int j = i*i; j <= MAX; j += i)
                bs[j] = 1;
        }
    }
    
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
