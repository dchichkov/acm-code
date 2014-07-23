#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <stack>

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
stack<char> parens;
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
    debug(line, endl);
    REP(i, line.length())
    {
        switch (line[i])
        {
        case '(':
        case '[':
            parens.push(line[i]);
            break;
        case ')':
            if (parens.empty() || parens.top() != '(') //short circuit avoid segfault
                parens.push(line[i]);
            else parens.pop();
            break;
        case ']':
            if (parens.empty() || parens.top() != '[') //short circuit avoid segfault
                parens.push(line[i]);
            else parens.pop();
            break;
        }
    }

    printf("%s\n", parens.empty() ? "Yes" : "No");
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
        while (!parens.empty())
            parens.pop();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
