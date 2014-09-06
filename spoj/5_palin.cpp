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
    int mid = (line.length()-1)/2;
    if (line.length() % 2 == 1)
    {
        line[mid]++;
        //reflect
        debug(mid, endl);
        for (int i = mid, j = mid; i >= 0; i--, j++)
        {
            line[j] = line[i];
        }
    }
    else
    {
        if (line[mid] <= line[mid+1])
            line[mid]++;
        //reflect
        debug(mid, endl);
        for (int i = mid, j = mid+1; i >= 0; i--, j++)
        {
            line[j] = line[i];
        }
    }

    //handle the 9s
    for (int i = mid, j = mid+1; i >= 0; i--, j++)
    {
        debug((line[i] == 0x3A), TAB); debug((int)line[i] - 0x3A, endl);
        if (line[i] == 0x3A)
        {

            debug(i, TAB); debug(j, TAB); debug(line[i-1], TAB);
            debug(line[j+1], endl);
            line[i] = 0x30;
            line[j] = 0x30;
            if (i == 0)
                line.insert(0, "1");
            else
                line[i-1]++;
            if (j != line.length()-1)
                line[j+1]++;
            else
                line[j] = line[i-1];
        }
    }
    printf("%s\n", line.c_str());
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
