#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>

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
typedef unsigned long long ull;
ull facts[30];
string line;
map<char, int> cont;
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
        cont[line[i]]++;
    return true;
}

void process()
{
    //process input
    ull a = 1, b = facts[line.length()];
    for(map<char, int>::iterator it = cont.begin(); it != cont.end(); ++it)
        b /= facts[it->second];
    
    printf("%llu\n", b);
}

int main()
{
    FOR(i, 1, 21)
        facts[i] = i;
        
    FOR(i, 2, 21)
        facts[i] *= facts[i-1];
    
    debug(facts[20], endl);
    int tc, cnt = 0;
    scanf("%d " , &tc);
    while (tc-- > 0)
    {
        printf("Data set %d: ", ++cnt);
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        cont.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
