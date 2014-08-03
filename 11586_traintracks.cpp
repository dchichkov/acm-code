#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <sstream>

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
stringstream str;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    getline(cin, line);
    str << line;
    return true;
}

void process()
{
    //process input
    vector<string> mff;
    string mf;
    int fe = 0, ma = 0;
    while (str >> mf)
    {
        mff.push_back(mf);
    }
    if (mff.size() == 1)
        printf("NO LOOP");
    else
    {
        REP(i, (int)mff.size())
        {
            ma += count(mff[i].begin(), mff[i].end(), 'M');
            fe += count(mff[i].begin(), mff[i].end(), 'F');
            
        }

        if (fe == ma)
            printf("LOOP");
        else
            printf("NO LOOP");
    }
    puts("");
}

int main()
{
    int nc;
    cin >> nc;
    cin.ignore(1, '\n');
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        str.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
