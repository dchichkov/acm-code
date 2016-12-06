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
    //do
        //{
        if (cin.eof()) return false;
        getline(cin, line);

        if (cin.peek() == cin.eof()) return false;
        
        //} while (line.length() == 0);

    return true;
}

void process()
{
    //process input
    string tmp, tmp2;
    int mpt;
    stringstream str;
    if (isdigit(line[0]))
    {
        REP(i, line.length())
        {
            tmp2.clear();
            if (i+2 < line.length())
            {
                debug(line[i], TAB); debug(line[i+1], TAB); debug(line[i+2], endl);
                tmp2 += line[i+2];
                tmp2 += line[i+1];
                tmp2 += line[i];
                sscanf(tmp2.c_str(), "%d", &mpt);
            }
            else
            {
                debug(line[i], TAB); debug(line[i+1], endl);
                tmp2 += line[i+1];
                tmp2 += line[i];
                sscanf(tmp2.c_str(), "%d", &mpt);
            }
            debug(tmp2, TAB); debug(mpt, endl);
            if (mpt < 100 || mpt > 122)
            {
                tmp2.clear();
                tmp2 += line[i+1];
                tmp2 += line[i];
                sscanf(tmp2.c_str(), "%d", &mpt);
                i += 1;
            }
            else
                i += 2;
            debug(tmp2, TAB); debug(mpt, endl);

            tmp += (char)mpt;

        }
    }
    else
    {
        REP(i, line.length())
        {
            str << (int)line[i];   
        }
        str >> tmp;    
    }
    reverse(tmp.begin(), tmp.end());
    cout << tmp << endl;

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
