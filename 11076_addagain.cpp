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
string num;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int nnums;
    scanf("%d ", &nnums);
    if (nnums == 0) return false;

    int n;
    getline(cin, num);
    REP(i, num.length())
    {
        if (num[i] == ' ')
        {
            num.erase(i, 1);
            i--;
        }
    }
    
    SORT(num);
    
    return true;
}

void process()
{
    //process input
    long long ans = 0, m;

    do {
       
        sscanf(num.c_str(), "%lld", &m);
        ans += m;
        
    } while (next_permutation(num.begin(), num.end()));

    printf("%lld\n", ans);
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
