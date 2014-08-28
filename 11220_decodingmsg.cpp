#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <sstream>

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

/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    string line, word, decode;
    int i = 0;
    stringstream str;
    while (getline(cin, line), line.compare("") != 0)
    {
        i = 0;
        str.str(line);
        while(str >> word)
        {
            debug(word, endl);
            if (word.length() < i+1)
                continue;

            decode += word[i++];
        }
        str.str("");
        str.clear();
        cout << decode << endl;
        
        decode.clear();
        if (cin.eof()) break;
    }
    return true;
}

void process()
{
    //process input
}

int main()
{
    int nc;
    scanf("%d ", &nc);
    int count = 0;
    while (nc-- > 0)
    {
        cout << "Case #" << ++count << ":" << endl;
        getInput();
        process();
        if (nc != 0) cout << endl;
        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
