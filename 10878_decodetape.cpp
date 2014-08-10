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
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    char letter;
    char ltr = 0;
    int ctr = 0;
    while ((letter = getchar()) != EOF)
    {
        switch (letter)
        {
        case ' ':
            ++ctr;
            ltr <<= 1;
            debug((int)ltr, TAB);
            break;
        case 'o':
            ++ctr;
            ltr <<= 1;
            ltr += 1;
            debug((int)ltr, TAB);
            break;
        }
        if (ctr == 8)
        {
            debug(ltr, endl);
            line += ltr;
            ltr = 0;
            ctr = 0;
        }
    }
    return true;
}

void process()
{
    //process input
    printf("%s", line.c_str());
}

int main()
{
    //while ()
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
