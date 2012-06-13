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
double mi_[6];
int    gy_[6];
int    r_[6];
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

bool process(int open, int closed, int speed, double distance)
{
    debug(open, TAB); debug(closed, TAB); debug(speed, TAB); debug(distance, endl);
    //process input
    debug(distance/speed, endl);
    int time_it_takes = (distance*3600/speed); //hours to seconds
    debug(time_it_takes, endl);
    int check = time_it_takes%(open+closed);//(int)fmod(time_it_takes, (open+closed));
    debug(check, endl);
    if (check < open)
        return true;
    else if (check >= open)
        return false;
    
}

void clear()
{
    for (int i = 0; i < 6; ++i)
    {
        mi_[i] = 0;
        gy_[i] = 0;
        r_[i]  = 0;
    }
}
            
int main()
{
    int num_cases = 0, g, y, r;
    double mi;
    scanf("%d", &num_cases);
    int case_count = 0;
    while (num_cases != -1)
    {
        vi successful_speeds;
        for (int i = 0; i < num_cases; ++i)
        {
            scanf("%lf %d %d %d", &mi, &g, &y, &r);
            mi_[i] = mi;
            gy_[i] = g+y;
            r_[i] = r;
        }

        for (int speed = 30; speed <= 60; ++speed)
        {
            bool success = false;
            for (int i = 0; i < num_cases; ++i)
            {
                if (!process(gy_[i], r_[i], speed, mi_[i]))
                    break;

                if (i == num_cases - 1)
                    success = true;
            }
            if (num_cases == 0) success = true;
            if (success)
            {
                successful_speeds.push_back(speed);
                debug(speed, TAB);
            }
            else
            {
                successful_speeds.push_back(-1);
            }
        }
        int low = 0, high = 0;
        printf("Case %d: ", ++case_count);
        if (count(successful_speeds.begin(), successful_speeds.end(), -1) == 31)
        {
            printf("No acceptable speeds.");
        }
        else
        {
            for (vi::iterator it = successful_speeds.begin(); it != successful_speeds.end(); ++it)
            {
                if (*it != -1)
                {
                    if (low == 0) //not set yet
                    {
                        low = *it;
                    }
                    else
                    {
                        high = *it;
                    }
                }
                if (*it == -1 or (it+1) == successful_speeds.end())
                { //print it out
                    if ((it+1) == successful_speeds.end() and low and high)
                        printf("%d-%d", low, high);
                    else if ((it+1) == successful_speeds.end() and low)
                        printf("%d", low);
                    else if (low and high)
                    {
                        printf("%d-%d, ", low, high);
                    }
                    else if (low)
                    {
                        printf("%d, ", low);
                    }
                    
                    low = high = 0;
                }
                //printf("%d, ", *it);
            }
        }
        printf("\n");
        clear();
        scanf("%d", &num_cases);
    }
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
