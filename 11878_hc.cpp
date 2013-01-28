#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

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
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
char op;
int a, b, ans;
int count;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    scanf("%d", &a);
    scanf("%c", &op);
    scanf("%d=", &b);
    
    return true;
}

void process()
{
    char thr = getc(stdin);
    if (thr == '?')
        return;
    else
        ungetc(thr, stdin);

    scanf("%d ", &ans);
    
    //process input
    debug(a, TAB);
    debug(op, TAB);
    debug(b, TAB);
    debug(ans, endl);

    
    switch(op)
    {
    case '+':
        if (a + b == ans)
            count++;
        break;
    case '-':
        if (a - b == ans)
            count++;
        break;
    }
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }
    printf("%d\n", count);

    return 0;
}
