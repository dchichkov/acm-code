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
    getline(cin, line);
    return true;
}

void process()
{
    //process input
    bool valid = true, l = true, m = false;
    int a = 0, b = 0, c = 0;
    debug(line, TAB);
    REP(i, line.length())
    {
        if (line[i] != '?' && line[i] != 'M' && line[i] != 'E')
        {
            valid = false;
            break;
        }

        if (line[i] == 'M')
        {
            if (m)
            {
                valid = false;
                break;
            }
            m = true;
        }
        else if (line[i] == 'E')
        {
            if (!l)
            {
                valid = false;
                break;
            }
            
            l = false;
        }
        else if (line[i] == '?')
            l ? (m ? c++ : a++) : b++;
    }
    debug(a, TAB); debug(c, TAB); debug(b, endl);
    bool omg = false;
    if (a && b && c)
    {
        if (c == 1 && (a+1 != b))
            valid = false;
        else
            omg = true;
        if (!omg && (a < 1 || c < 2 || b < 2) || (a+c > b))
            valid = false;
    }
    else valid = false;
    
    printf("%s\n", (valid) ? "theorem" : "no-theorem");
}

int main()
{
    int nc;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
