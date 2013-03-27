#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <cctype>

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
int a, b;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    getline(cin, line);
    REP(i, line.length())
    {
        if (line[i] == 'x')
        {
            if (i == 0 || !isdigit(line[i-1]))
                line.insert(i, "1");
        }
        else if ((line[i] == '+' || line[i] == '-' || line[i] == '=')  && isdigit(line[i-1]))
        {
            line.insert(i, "y");
            i++;
        }
        else if (i+1 == line.length() && isdigit(line[i++]))
            line.append("y");

    }
    debug(line, endl);
    return true;
}

void process()
{
    //process input
    istringstream ss(line);

    int x;
    char c;
    bool polarity = 0;
    while (!ss.eof())
    {
        ss >> x;
        debug(x, TAB);
        ss >> c;
        debug(c, endl);
        switch (c)
        {
        case 'x':
            debug( ((polarity) ? -x : x) , endl);
            a += (polarity) ? -x : x;
            break;
        case 'y':
            debug( ((polarity) ? x : -x) , endl);
            b += (polarity) ? x : -x;
            break;            
        }
        if (ss.peek() == '=')
        {
            polarity = !polarity;   
            ss.get();
        }
        else if (ss.peek() == '+') ss.get();
        debug(a, TAB); debug(b, endl);
    }
    debug(a, TAB); debug(b, endl);

    if (b != 0 && a != 0)
        printf("%d", (int)floor((double)b/a));
    else
        printf("%s", (a == 0 ? (b == 0 ? "IDENTITY" : "IMPOSSIBLE") : "WTF"));
}

int main()
{
    int nc;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();
        if (nc != 0)
            puts("");
        /*CLEAR GLOBAL VARIABLES!*/

        a = b = 0;
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
