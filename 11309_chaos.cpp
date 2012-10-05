#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

#define DEBUG
//#undef DEBUG //uncomment this line to pull out print statements
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
int a, b;
char c[5], d[5];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d:%d", &a, &b);
    return true;
}

void process()
{
    //process input
    if (a == 0 && b < 9)
        b += 1;
    else
    {
        int p;
        sprintf(c, "%02d", a);
        sprintf(d, "%02d", b);
        //turn around
        char e = c[0];
        c[0] = c[1];
        c[1] = e;

        sscanf(c, "%d", &p);
        if (p > b) {
            b = p;
        }
        else if (p < b)
        {
            a = (a+1)%24;
            sprintf(c, "%02d", a);
            //turn around
            char e = c[0];
            c[0] = c[1];
            c[1] = e;
            sscanf(c, "%d", &b);
        }
    }

    printf("%02d:%02d\n", a, b);
}

int main()
{
    int nc;
    scanf("%d", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
