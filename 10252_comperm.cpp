#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define DEBUG
//#undef DEBUG //uncomment this line to pull out print statements
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
string line1, line2;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    getline(cin, line1);
    getline(cin, line2);

    string line;
    line.clear();
    REP(i, line1.length())
        if (isalpha(line1[i]) && islower(line1[i]))
            line += line1[i];

    line1 = line;
    line.clear();

    REP(i, line2.length())
        if (isalpha(line2[i]) && islower(line2[i]))
            line += line2[i];

    line2 = line;
    return true;
}

void process()
{
    //process input
    vector<char> a;
    size_t pos = 0;
    REP(i, line1.length())
    {
        pos = line2.find(line1[i]);
        if (pos != string::npos)
        {
            a.push_back(line1[i]);
            line2.erase(pos, 1);
        }
    }

    SORT(a);
    for (vector<char>::iterator it = a.begin(); it != a.end(); ++it)
        cout << *it;
    cout << endl;
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
