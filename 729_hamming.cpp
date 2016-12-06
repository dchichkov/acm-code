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
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int a, b;
vector<char> str;
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

void process()
{
    //process input
    REP(i, a-b)
    {
        str.push_back('0');
    }
    REP(i, b)
    {
        str.push_back('1');
    }

    do
    {
        REP(i, (int)str.size())
            printf("%c", str[i]);

        puts("");
    } while (next_permutation(str.begin(), str.end()));
}

int main()
{
    int nc;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();
        if (nc != 0)
            puts("");
        /*CLEAR GLOBAL VARIABLES!*/
        str.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
