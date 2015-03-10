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
string line;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    getline(cin, line);
    if (line.compare("0") == 0) return false;
    return true;
}

void process()
{
    //process input
    int N = 0, j = 1;
    REP(i, line.length())
    {
        N += line[i]-0x30;
    }
    if (N%9 == 0)
    {
        char w[10];
        while (N > 9)
        {
            sprintf(w, "%d", N);
            N = 0;
            REP(i, strlen(w))
            {
                N += w[i]-0x30;
            }
            j++;
        }
        printf("%s is a multiple of 9 and has 9-degree %d.", line.c_str(), j);
    }
    else
        printf("%s is not a multiple of 9.", line.c_str());
    puts("");
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
