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
int num;
/*global variables*/

void tobin(unsigned int a)
{
    int r = 0;
    while (r != sizeof(a)*8)
    {
        a >>= 1;
        printf("%d", a%2);
        ++r;
    }
}

void dump(int a)
{
    //dump data
    tobin(a);
    cout << endl;
}

bool getInput()
{
    //get input
    num = 0;
    if (scanf("%d", &num) == EOF) return false;
    return true;
}

void process()
{
    //process input
    int onum = 0;
    int a = 0xFF000000,
        b = 0x00FF0000,
        c = 0x0000FF00,
        d = 0x000000FF;

    onum |= (d&num)<<24;
    onum |= (c&num)<<8;
    onum |= ((b&num)>>8)&c;
    onum |= ((a&num)>>24)&d;

    printf("%d converts to %d\n", num, onum);
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
