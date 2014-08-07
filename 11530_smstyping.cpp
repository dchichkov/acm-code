#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>

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
string line;
map<char, int> pad;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    getline(cin, line);
    return true;
}

void process()
{
    //process input
    int total = 0;
    REP(i, line.length())
    {
        total += pad[line[i]];
    }
    printf("%d\n", total);
}

int main()
{
    pad['a'] = 1;
    pad['b'] = 2;
    pad['c'] = 3;
    pad['d'] = 1;
    pad['e'] = 2;
    pad['f'] = 3;
    pad['g'] = 1;
    pad['h'] = 2;
    pad['i'] = 3;
    pad['j'] = 1;
    pad['k'] = 2;
    pad['l'] = 3;
    pad['m'] = 1;
    pad['n'] = 2;
    pad['o'] = 3;
    pad['p'] = 1;
    pad['q'] = 2;
    pad['r'] = 3;
    pad['s'] = 4;
    pad['t'] = 1;
    pad['u'] = 2;
    pad['v'] = 3;
    pad['w'] = 1;
    pad['x'] = 2;
    pad['y'] = 3;
    pad['z'] = 4;
    pad[' '] = 1;
    int count = 0;
    int nc;
    scanf("%d", &nc);
    getline(cin, line);
    while (nc-- > 0)
    {
        getInput();
        printf("Case #%d: ", ++count);
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
