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
int start, end;
int smeet, emeet;
int a,b;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d:%d", &a, &b);
    start = a*100+b;
    scanf("%d:%d", &a, &b);
    end = a*100+b;
    scanf("%d:%d", &a, &b);
    smeet = a*100+b;
    scanf("%d:%d", &a, &b);
    emeet = a*100+b;
    return true;
}

void process()
{
    //process input
    if (/*something*/)
        printf("Mrs Meeting");
    else
        printf("Hits Meeting");

    printf("\n\n");
}

int main()
{
    int nc, count = 0;
    scanf("%d", &nc);
    while (nc-- > 0)
    {
        printf("Case %d: ", ++count);
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
