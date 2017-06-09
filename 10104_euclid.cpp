#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

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
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,(int)n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int a, b;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    scanf("%d %d ", &a, &b);
    return true;
}

void process()
{

    //extended euclid... wow
    //so simple. got the code from the wiki page.
    int s = 0, old_s = 1, t = 1, old_t = 0, r = b, old_r = a;
    int temp;
    int quotient;
    while (r != 0)
    {
        quotient = old_r / r;
        temp = r;
        r = old_r - (quotient * r);
        old_r = temp;

        temp = s;
        s = old_s - (quotient * s);
        old_s = temp;

        temp = t ;
        t = old_t - (quotient * t);
        old_t = temp;
    }
    /*cout << "Bezout coefficients: " << old_s << " " << old_t << "\n";
    cout << "gcd " << old_r << "\n";
    cout << "quotients by the gcd: " << t << " " << s << endl; */
    printf("%d %d %d\n", old_s, old_t, old_r);
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
