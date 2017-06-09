#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

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
string line;
#define EPS 1e-9
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    char st[10010];
    fgets(st, 10010, stdin);
    REP(i, strlen(st))
    {
        if (isalpha(st[i]))
            line += st[i];
    }
    
    return true;
}

void process()
{
    //process input
    int sqr = sqrt(line.length());
    string line2;
    line2 = line;
    reverse(line2.begin(), line2.end());
    debug(line, endl);
    debug(line2, endl);
    if (sqr*sqr == line.length() && line.compare(line2) == 0)
    {
        printf("%d", sqr);
    }
    else
    {
        printf("No magic :(");
    }
    puts("");
           
}

int main()
{
    int nc;
    scanf("%d ", &nc);
    int count = 1;
    while (nc-- > 0)
    {
        printf("Case #%d:\n", count++);
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        line.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
