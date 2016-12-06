#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>

using namespace std;

#define DEBUG
#undef DEBUG //uncomment this line to pull out print statements
#ifdef DEBUG
#define TAB '\t'
#define debug(a, end) cout << #a << ": " << a << end
#else
#define debug(a, end)
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
string line;
/*global variables*/

void dump()
{
    //dump data
}

bool is_palindrome(const string& s)
{
    string x;
    for (size_t i = 0; i < s.length(); ++i)
        if (isalpha(s[i]))
            x += tolower(s[i]);

    for (size_t i = 0; i < x.length()/2; ++i)
    {
        debug(x[i], TAB); debug(x[x.length()-i-1], endl);
        if (x[i] != x[x.length()-i-1]) return false;
    }

    return true;
}

bool getInput()
{

    getline(cin, line);
    if (line == "DONE") return false;
    //get input
    return true;
}

void process()
{
    //process input
    printf("%s\n", is_palindrome(line) ? "You won't be eaten!" : "Uh oh..");
}

int main()
{
    while (getInput())
    {

        process();

        /*output*/


        /*output*/
    }

    return 0;
}
