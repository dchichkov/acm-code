#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iomanip>

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
vector<string> fls;
int longest;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int a;
    cin >> a;    
    if (cin.eof()) return false;

    string name;
    REP(i, a)
    {
        cin >> name;
        fls.push_back(name);
        longest = max(longest, (int)name.length());
    }
    return true;
}

void process()
{
    //process input
    SORT(fls);
    int num_cols = 60 / longest;
    int sz = fls.size();
    int num_rows = sz / num_cols;
    REP(i, fls.size())
    {
        REP(j, num_rows)
        {
            cout << fls[min(sz-1, (j*num_cols)+i)] << setw(longest+2);
            i++;
        }
        cout << endl;
    }
    cout << setfill('-') << setw(60) << endl << endl;
    setfill(' '); setw(0);
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
