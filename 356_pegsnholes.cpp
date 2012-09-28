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
bool first_time = true;
const double PI = acos(-1.0);
int n;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (scanf("%d\n", &n) == EOF) return false;
    if (!first_time) printf("\n");
    else first_time = false;
    return true;
}

bool in_circle(const point& x, double radius)
{
    double y = (x.first*x.first + x.second*x.second);
    if (y < (radius*radius))
    { debug(y, TAB); debug(radius, endl); }
    return y <= (radius*radius);
}

void process()
{
    //process input
    //int t = (int)ceil(((2*n-1)*(2*n-1))/4*PI)/4;
    double r = (double)(2*n-1)/2;
    int in = 0, out = 0;
    point x;
    REP(i, n)
    {
        REP(j, n)
        {
            x.first = i;
            x.second = j; //top left
            if (in_circle(x, r))
            {
                debug("contained segment", endl);
                out++;
                x.first = i+1;
                x.second = j+1; //bottom right
                if (in_circle(x, r))
                {
                    debug("fully in", endl);
                    in++; out--;
                }
            }
        }
    }
    
    
    
    printf("In the case n = %d, %d cells contain segments of the circle.\n", n, out*4);
    printf("There are %d cells completely contained in the circle.\n", in*4);
}

int main()
{

    while (getInput())
    {

        process();

        /*output*/


        /*output*/
    }

    return 0;
}
