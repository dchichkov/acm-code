#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

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
int num_in;
vp points;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d\n", &num_in);
    if (num_in == 0)
        return false;
    return true;
}

void process()
{
    //process input
    REP(i, num_in)
    {
        int a, b;
        scanf("%d %d\n", &a, &b);
        point x; x.first = a; x.second = b;
        points.push_back(x);
    }

    point midpoint = points[(num_in+1)/2-1];
    debug(midpoint.first, TAB); debug(midpoint.second, endl);
    int stan = 0, ollie = 0;

    for (vp::iterator it = points.begin(); it != points.end(); ++it)
    {
        if ((it->first > midpoint.first && it->second > midpoint.second) ||
            (it->first < midpoint.first && it->second < midpoint.second))
            stan++;
        else if ((it->first > midpoint.first && it->second < midpoint.second) ||
                 (it->first < midpoint.first && it->second > midpoint.second))
            ollie++;
    }

    printf("%d %d\n", stan, ollie);
}

int main()
{
    bool moreToDo;
    while (moreToDo = getInput())
    {

        process();

        /*output*/


        /*output*/

        points.clear();
    }

    return 0;
}
