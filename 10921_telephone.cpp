#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <map>
#include <typeinfo>

using namespace std;

#define DEBUG  //comment this line to pull out print statements
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
map<char, int> nums;
string line;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (cin.eof()) return false;
    getline(cin, line);
    if (line.length() == 0) return false;
    return true;
}

void process()
{
    //process input
    REP(i, line.length())
    {
        if (isalpha(line[i]))
            line[i] = nums[line[i]] + 0x30;
    }
    cout << line << endl;
}

int main()
{
    nums['A'] = 2;
    nums['B'] = 2;
    nums['C'] = 2;
    nums['D'] = 3;
    nums['E'] = 3;
    nums['F'] = 3;
    nums['G'] = 4;
    nums['H'] = 4;
    nums['I'] = 4;
    nums['J'] = 5;
    nums['K'] = 5;
    nums['L'] = 5;
    nums['M'] = 6;
    nums['N'] = 6;
    nums['O'] = 6;
    nums['P'] = 7;
    nums['Q'] = 7;
    nums['R'] = 7;
    nums['S'] = 7;
    nums['T'] = 8;
    nums['U'] = 8;
    nums['V'] = 8;
    nums['W'] = 9;
    nums['X'] = 9;
    nums['Y'] = 9;
    nums['Z'] = 9;
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
