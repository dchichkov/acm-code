#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <map>
#include <algorithm>

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
typedef long long int64; //for clarity
typedef vector<int> vi; //?
typedef vector<point> vp; //?
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } //change min
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } //change max

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
map<char, int> weight;
char line1[30];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (scanf("%20s", line1) == EOF) return false;
    return true;
}

void process()
{
    //process input
    string line = line1;
    string lol;
    for (string::iterator it = line.begin(); it != line.end(); ++it)
    {
        if (weight.find(*it) != weight.end())
            lol += '0'+weight[*it];
        else
            lol += '0';
    }
    lol.erase(unique(lol.begin(),lol.end()),lol.end());
    lol.erase(remove(lol.begin(), lol.end(), '0'), lol.end());
    
    cout << lol << endl;
}

int main()
{
    weight['B'] = weight['F'] = weight['P'] = weight['V'] = 1;
    weight['C'] = weight['G'] = weight['J'] = weight['K'] = weight['Q'] = weight['S'] = weight['X'] = weight['Z'] = 2;
    weight['D'] = weight['T'] = 3;
    weight['L'] = 4;
    weight['M'] = weight['N'] = 5;
    weight['R'] = 6;
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
