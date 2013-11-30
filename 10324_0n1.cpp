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
string zsandones;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (cin.eof()) return false;

    cin >> zsandones;
    debug(zsandones, endl);
    if (zsandones.length() == 0) return false;
    return true;
}

void process()
{
    //process input
    int num_cases, x, y, start, end;
    char check_char;
    cin >> num_cases;
    REP(i, num_cases)
    {
        cin >> x >> y;
        debug(x, TAB); debug(y, endl);
        start = min(x, y);
        end = max(x, y);
        debug(start, TAB); debug(end, endl);
        check_char = zsandones.at(start);
        debug(zsandones.substr(start, end-start+1), TAB);
        debug(check_char, endl);
        if (zsandones.substr(start, end-start+1).find_first_not_of(check_char) == string::npos)
        {
            cout << "Yes";
        }
        else cout << "No";

        cout << endl;
    }
}

int main()
{
    int case_number = 1;
    while (getInput())
    {

        cout << "Case " << case_number++ << ":" << endl;
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        zsandones.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
