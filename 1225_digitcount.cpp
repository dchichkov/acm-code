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
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
map<char, int> cnt;
string line;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int a;
    scanf("%d ", &a);
    char b[10020];
    FOR(i, 1, a+1)
    {
        sprintf(b, "%d", i);
        line.append(b);
    }
    return true;
}

void process()
{
    //process input
    cnt['0'] = 0;
    cnt['1'] = 0;
    cnt['2'] = 0;
    cnt['3'] = 0;
    cnt['4'] = 0;
    cnt['5'] = 0;
    cnt['6'] = 0;
    cnt['7'] = 0;
    cnt['8'] = 0;
    cnt['9'] = 0;
    REP(i, line.length())
    {
        cnt[line[i]]++;
    }

    printf("%d", cnt['0']);
    FOR(i, 1, 10)
    {
        printf(" %d", cnt[i+0x30]);
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

        /*CLEAR GLOBAL VARIABLES!*/
        cnt.clear();
        line.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
