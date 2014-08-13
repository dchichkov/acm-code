#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>

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
map<int, vi> squares;
int n;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (scanf("%d ", &n) == EOF) return false;
    return true;
}

void process()
{
    //process input
    switch(n)
    {
    case 2:
        REP(i, squares[n].size())
            printf("%02d\n", squares[n][i]);
        break;
    case 4:
        REP(i, squares[n].size())
            printf("%04d\n", squares[n][i]);
        break;
    case 6:
        REP(i, squares[n].size())
            printf("%06d\n", squares[n][i]);
        break;
    case 8:
        REP(i, squares[n].size())
            printf("%08d\n", squares[n][i]);
        break;
    }
}

int main()
{
    //pre-compute
    int a, b;
    FOR(i, 0, 99)
    {
        a = i/10;
        b = i%10;
        if ((a+b)*(a+b) == i) squares[2].push_back(i);
    }
    FOR(i, 0, 9999)
    {
        a = i/100;
        b = i%100;
        if ((a+b)*(a+b) == i) squares[4].push_back(i);
    }
    FOR(i, 0, 999999)
    {
        a = i/1000;
        b = i%1000;
        if ((a+b)*(a+b) == i) squares[6].push_back(i);
    }
    FOR(i, 0, 99999999)
    {
        a = i/10000;
        b = i%10000;
        if ((a+b)*(a+b) == i) squares[8].push_back(i);
    }
    
    
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
