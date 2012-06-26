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
    int first, second, third, fourth;
    double turns;
    double num_degrees = 0;
    while (scanf("%d %d %d %d", &first, &second, &third, &fourth))
    {
        debug(first, TAB); debug(second, TAB); debug(third, TAB); debug(fourth, endl);
        if (first == 0 and second == 0 and third == 0 and fourth == 0)
            break;
        turns = 2;
        turns += ((double)abs(first-second)/40);
        debug((double)abs(first-second)/40, TAB);
        turns += 1;
        turns += ((double)(abs(abs(first-second)-third))/40);
        debug(((double)(abs(abs(first-second)-third))/40), TAB);
        turns += ((double)(abs(third-fourth))/40);
        debug(((double)abs(third-fourth))/40, TAB);
        debug(turns,endl);
        cout << (turns*360) << endl;

        /*num_degrees += 720; //two full turns
        pos = abs(second-first); //goto first number
        num_degrees += 360/pos; 
        num_degrees += 360; //add another turn
        pos = abs(third-pos); //goto second number
        */

        /*output*/


        /*output*/
    }
}
