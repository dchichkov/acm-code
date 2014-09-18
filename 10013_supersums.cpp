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
char n1[1000010], n2[10000010];
int nd;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int a, b;
    scanf("%d ", &nd);
    REP(i, nd)
    {
        scanf("%d %d ", &a, &b);
        n1[nd-i-1] = a;
        n2[nd-i-1] = b;
    }
    return true;
}

void process()
{
    //process input
    for (int i = strlen(n1); i >= 0; --i)
        n1[i] = n1[i-1] + n2[i-1];

    n1[0] = '0';
    for (int i = strlen(n1); i >= 0; --i)
        if (n1[i] > 0x3A)
        {
            n1[i] = n1[i]-0x3A;
            n1[i-1] += 1;
        }

    printf("%s\n", n1);
}

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc-- > 0)
    {
        CL(n1, 0);
        CL(n2, 0);
        getInput();
        process();
        if (tc != 0) puts("");
        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
