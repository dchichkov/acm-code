#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <limits>

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
int n, b, h, w, p, a;

/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (scanf("%d %d %d %d", &n, &b, &h, &w) == EOF)
        return false;
    return true;
}

void process()
{
    //process input
    int price;
    int num_beds;
    int minimum = numeric_limits<int>::max();
    REP(i, h)
    {
        scanf("%d", &price);
        REP(j, w) //dunno why I'm iterating, seems kind of redundant
        {
            scanf("%d", &num_beds);
            if (num_beds < n) continue;
            else minimum = min(n*price, minimum);
        }
    }

    (minimum == numeric_limits<int>::max() || minimum > b) ? printf("%s\n", "stay home") : printf("%d\n", minimum); 
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
