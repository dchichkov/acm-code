#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <limits>

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
int N;
string line[20];
/*global variables*/

void dump()
{
    //dump data
}

int c_ws(const string& s)
{
    size_t pos = s.find_first_of(" ");
    int count = 0;
    while (pos != string::npos)
    {
        ++count;
        pos = s.find_first_of(" ", pos+1);
    }

    return count;
}

bool getInput()
{
    //get input
    scanf("%d\n", &N);
    if (N == 0) return false;
    return true;
}

void process()
{
    //process input
    int min_ws = numeric_limits<int>::max();

    REP(i, N)
    {
        getline(cin, line[i]);
        debug(line[i], endl);
        min_ws = min(c_ws(line[i]), min_ws);
    }
    debug(min_ws, endl);
    int total = 0;
    REP(i, N)
        total += c_ws(line[i])-min_ws;

    printf("%d\n", total);
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
