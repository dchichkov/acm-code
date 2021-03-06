#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <list>

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
string line;
list<char> str;
list<char>::iterator it;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    getline(cin, line);
    if (cin.eof() || line.compare("") == 0) return false;
    it = str.end();
    REP(i, line.length())
    {
        switch(line[i])
        {
        case '[':
            it = str.begin()++;
            break;
        case ']':
            it = str.end();
            break;
        default:
            it = str.insert(it, line[i]);
            ++it;
            debug(str.size(), TAB); debug(str.back(), endl);
            break;
        }
    }
    debug(str.size(), endl);
    while (!str.empty())
    {
        printf("%c", str.front());
        str.pop_front();
    }
    puts("");

    return true;
}

void process()
{
    //process input
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        str.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
