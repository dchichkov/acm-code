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
vector<string> command;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int numc;
    scanf("%d ", &numc);
    string in;
    REP(i, numc)
    {
        getline(cin, in);
        command.push_back(in);
    }
    return true;
}

void process()
{
    //process input
    int position = 0;
    int num_com;
    string s;
    stringstream ss;
    REP(i, command.size())
    {
        debug(command[i], TAB); debug(command[i][0], endl);
        switch(command[i][0])
        {
        case 'R':
            position++;
            break;
        case 'L':
            position--;
            break;
        case 'S':
            ss.str(command[i]);
            ss >> s >> s >> num_com;
            debug(num_com, endl);
            command.insert(command.begin()+i+1, command[num_com-1]);
        }
    }
            
    printf("%d\n", position);
    
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
        command.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
