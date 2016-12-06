#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iomanip>

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
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
vector<string> fls;
int longest;
int a;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    cin >> a;    
    if (cin.eof()) return false;

    string name;
    REP(i, a)
    {
        cin >> name;
        debug(name, endl);
        fls.push_back(name);
        longest = max(longest, (int)name.length());
    }
    return true;
}

void process()
{
    //process input

    int rm = longest;
    int col_width = longest+2;
    SORT(fls);
    debug(rm, TAB); debug(col_width, endl);
    int rows;
    int cols = 60 / col_width;
    if (cols == 0) cols = 1;
    if (rm+col_width == 60) cols = 2;
    rows = a / cols;
    if (rows * cols < a) ++rows;

    for (int i = 0; i < 60; ++i)
        cout << "-";
    cout << endl;
    
    int b = 0, c = 0;
    for (int i = 0; i < rows; ++i)
    {
        b = c;
        for (int j = 0, z = col_width; j < 61; j += z)
        {
            if (b >= a) break;
            if (b+rows >= a) z -= 2;
            cout << left << setw(z) << fls[b];
            b += rows;
        }
        cout << endl;
        c++;
    }

    debug(cols, endl);
    debug(rows, endl);
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        fls.clear();
        longest = 0;
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
