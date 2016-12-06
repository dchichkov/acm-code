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
int T, N;
point bpos, bend;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    scanf("%d\n", &T);
    scanf("%d\n", &N);
    //get input
    return true;
}

void process()
{
    debug(T, endl);
    REP(i, T)
    {
        scanf("%d %d %d %d", &bpos.first, &bpos.second, &bend.first, &bend.second);
        if ((bpos.first + bpos.second) %2 != (bend.first + bend.second)%2)
            printf("no move\n");
        else if (bpos.first == bend.first && bend.second == bpos.second)
            printf("0\n");
        else if (((double)abs(bpos.first - bend.first) / abs(bpos.second - bend.second))-1 == 0)
            printf("1\n");
        else
            printf("2\n");

    }
    //process input
}

int main()
{
    int nc;
    scanf("%d\n", &nc);
    debug(nc, endl);
    while (nc-- > 0)
    {
        getInput();
        process();

        /*output*/


        /*output*/
    }

    return 0;
}
