#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>

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

/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    
    return true;
}

void process()
{
    //process input
    set<string> dict;
    char w, t;
    string astr;
    while ((w = getchar()) != EOF)
    {
        if (isalpha(w))
        {
            astr += tolower(w);
        }
        else if (w == '-')
        {
            t = getchar();
            if (t == '\n')
                continue;
            else
                astr += w;
            ungetc(t, stdin);
        }
        else
        {
            //add it to the list
            if (astr != "")
                dict.insert(astr);
            astr = "";
        }
    }
    for (set<string>::iterator it = dict.begin(); it != dict.end(); ++it)
        cout << *it << endl;    
    
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
