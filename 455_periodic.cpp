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
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,(int)n)    
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

    cin >> line;
    return true;
}

void process()
{
    //process input
    string str, bstr;
    bool match;
    int i;
    for (i = 1; i < ((int)(line.length()+1)/2)+1; ++i)
    {
        str = line.substr(0, i);
        match = true;
        for (int j = 0; j < str.length(); ++j)
        {
            for (int k = i; k < line.length(); k += i)
            {
                if (str[j] != line[k+j])
                {
                    match = false;
                    break;
                }
            }
            if (!match)
                break;
        }
        if (match) break;
    }

    if (!match)        
        printf("%d\n", line.length());
    else
        printf("%d\n", i);
}

int main()
{
    int nc;
    cin >> nc;
    
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
        if (nc != 0) puts("");
    }

    return 0;
}
