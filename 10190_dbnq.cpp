#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

#define DEBUG  //comment this line to pull out print statements
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
long long a, b;
vector<long long> divs;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (scanf("%lld %lld", &a, &b) == EOF) return false;
    return true;
}

void process()
{
    //process input
    divs.push_back(a);

    if ((a != 0 && b != 0) &&
        (a > 1 && b != 1) && (a >= b))
    {
        while (a > 1)
        {
            if (a%b == 0)
                a /= b;
            else
                break;
            divs.push_back(a);
        }
        b = 0;
    }
    if (a == 1 && b == 0)
    {
        printf("%lld", divs[0]);
        FOR(i, 1, divs.size())
        {
            printf(" %lld", divs[i]);
        }
    }
    else printf("Boring!");

    printf("\n");
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        divs.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
