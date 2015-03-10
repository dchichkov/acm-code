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
long long total = 0;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    int nf, x, y, z;
    long long calc = 1;
    scanf("%d", &nf);
    REP (i, nf)
    {
        scanf("%d %d %d", &x, &y, &z);
        debug(x, TAB);         debug(y, TAB);         debug(z, endl);
        debug(animals, TAB);
        calc = x * z;;
        debug(calc, endl);
        
        total += calc;
        calc = 1;
    }
        
    //get input
    return true;
}

void process()
{
    //process input
    printf("%lld", total);
}

int main()
{
    int nc;
    scanf("%d", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();

        /*output*/
        total = 0;
        //if (nc != 0)
        printf("\n");
        /*output*/
    }

    return 0;
}
