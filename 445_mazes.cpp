#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <limits>

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
string line, pline;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (cin.eof()) return false;
    getline(cin, line);

    if (line.length() == 0 && cin.eof()) return false;
    
    return true;
}

void process()
{
    //process input
    debug(line, endl);
    int nt = 0;
    string out;
    REP(i, line.length())
    {
        if (line[i] >= '0' && line[i] <= '9')
            nt += line[i] - 0x30;
        else if (line[i] == '!')
            cout << endl;
        else
        {
            if (line[i] == 'b')
                out = " ";
            else
                out = line[i];

            REP(j, nt)
            {
                cout << out;
            }
            nt = 0;
        }
    }
    cout << endl;
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
