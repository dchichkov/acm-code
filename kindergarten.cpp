#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <cctype>
#include <map>
#include <set>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

#include <cfloat>
#include <utility>
/* //niche useful stuff
#include <iterator>    
#include <memory>
#include <functional>
#include <complex>
#include <bitset>
#include <cassert>
#include <regex.h> 
*/

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

/*global variables*/

/*global variables*/

bool isword(string s)
{
    for (string::iterator st = s.begin(); st != s.end(); ++st)
        if (isalpha(*st))
            return true;

    return false;
}

int main()
{
    string in;
    string space = " 0987654321,;.";
    size_t pos = 0, pos2 = 0;
    int counter = 0;
    while (getline(cin, in))
    {
        debug(in, endl);
        while ((pos = in.find_first_not_of(space, pos2)) != string::npos) //find words
        {

            pos2 = in.find_first_of(space, pos);
            if (pos2 == string::npos)
                pos2 = in.length();
            debug(in.substr(pos, pos2-pos), TAB);
            debug(pos, TAB); debug(pos2, endl);
            if (isword(in.substr(pos, pos2-pos)))
                ++counter;
        }

        cout << counter << endl;
        counter = 0;
        pos = pos2 = 0;
    }
}
