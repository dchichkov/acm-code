#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <cctype>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
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
//#undef DEBUG //uncomment this line to pull out print statements
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
    bool moreToDo;
    while (moreToDo = getInput())
    {

        process();

        /*output*/


        /*output*/
    }

    return 0;
}



/* topics to cover:
   stl algorithms
   stringstream(s) (advantage over itoa atoi)
   printf/scanf
   malloc/memset
   cstring(s)
   c++ strings
   climits
   cfloat
   utility
   functional
   cassert
   bitset
   memory
   complex
   regex.h

   reasons to use java:
   BigInteger
   GregorianCalendar

   things to do:
   sample problem sets for right before the competition
   problem sets that include niche programming things like converting strings to integers / memsets / using vectors + sets + maps / counting digits in a number / converting base of a number / --
*/
