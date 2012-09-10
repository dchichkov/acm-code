#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

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
int streak = 0;
int num_read;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    scanf("%d", &num_read);
    if (num_read == 0) return false;
    //get input
    return true;
}

void process()
{
    int num;
    int max1 = 0;
    REP(i, num_read)
    {
        scanf("%d", &num);
        streak += num;
        streak = max(streak, 0);
        max1 = max(streak, max1);
    }

    (streak == 0) ? printf("Losing streak.\n") : printf("The maximum winning streak is %d.\n", max1);
    streak = 0;
    //process input
}

int main()
{
    bool moreToDo;
    while (moreToDo = getInput())
    {

        process();

        /*output*/
        //CLEAR GLOBAL VARIABLES THAT NEED CLEARING ARGH

        /*output*/
    }

    return 0;
}
