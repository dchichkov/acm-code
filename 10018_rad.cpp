#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <sstream>
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
string num;
/*global variables*/

void dump()
{
    //dump data
}

string rev_n_add(string num)
{
    unsigned int c, d;
    sscanf(num.c_str(), "%ud", &c);
    reverse(num.begin(), num.end());
    sscanf(num.c_str(), "%ud", &d);

    c += d;
    
    stringstream ss;
    ss << c;
    ss >> num;
    return num;
}

bool is_palindrome(const string& s)
{
    REP(i, s.length()/2)
    {
        if (s[i] != s[s.length()-1-i])
            return false;
    }

    return true;
}

bool getInput()
{
    //get input
    cin >> num;
    return true;
}

void process()
{
    //process input
    int count = 0;
    while (!is_palindrome(num))
    {
        num = rev_n_add(num);
        ++count;
    }

    printf("%d %s\n", count, num.c_str());
}

int main()
{
    int nc;
    scanf("%d", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
