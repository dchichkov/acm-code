#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

#define DEBUG
//#undef DEBUG //uncomment this line to pull out print statements
#ifdef DEBUG
#define TAB '\t'
#define debug(a, end) cout << #a << ": " << a << end
#else
#define debug(a, end)
#endif

typedef pair<int, int> point;
typedef long long int64; //for clarity
typedef vector<int> vi; //?
typedef vector<point> vp; //?
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } //change min
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } //change max

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
string a, b;
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
    return true;
}

void process()
{
    //process input
    int total = 0;
    b = a;
    UN(a);
    total += a.length();
    a = b;

    for (int i = 2; i < a.length(); ++i)
    {
        for (int j = 0; j+i <= a.length(); ++j)
        {
            b = a;
            b = b.substr(j, i);
            reverse(b.begin(), b.end());
            debug(b, endl);
            if (a.substr(j, i).compare(b) == 0)
            {
                debug(a.substr(j, i), TAB); debug(b, endl);
                total++;
            }
        }
    }

    debug(total, endl);
    
}

int main()
{
    bool moreToDo;
    while (moreToDo = getInput())
    {

        process();

        /*output*/


        /*output*/
    }

    return 0;
}
