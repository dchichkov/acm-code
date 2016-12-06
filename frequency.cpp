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
#include <sstream>
#include <cstring>
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

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    return true;
}

void process()
{
    //process input
}

int main()
{
    char line[1000];
    map<char, short> count;
    while (fgets(line, 1000, stdin))
    {
        short maxn = 0;
        short size = strlen(line);
        debug(line, endl);
        debug(size, endl);
        for (short i = 0; i < size; ++i)
        {
            if (!isalpha(line[i])) continue;
            debug(line[i], TAB);
            debug(count[line[i]], endl);
            if (count[line[i]] or count[line[i]] == 0)
                count[line[i]]++;
            maxn = max(count[line[i]], maxn);
        }

        for (map<char, short>::iterator it = count.begin(); it != count.end(); ++it)
            if (it->second == maxn)
                printf("%c", it->first);

        printf(" %d\n", maxn);
        count.clear();
    }
}
