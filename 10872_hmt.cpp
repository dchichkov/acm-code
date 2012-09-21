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
int N;
long long int answer;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d", &N);
    if (N == 0) return false;
    return true;
}

void process()
{
    //process input
    debug(floor(N/2), endl);
    for (int i = 1; i <= floor(N/2); ++i)
    {
        for (int j = (N-i)/2; j >= floor(N/3); --j)
        {
            debug((N-i)/2, endl);
            for (int k = 1; k <= j; ++k)
            {
                debug(i, TAB); debug(j, TAB); debug(k, endl);
                if ((i + j + k) == N) answer++;
            }
        }
    }

    printf("%lld\n", answer);
}

int main()
{
    bool moreToDo;
    while (moreToDo = getInput())
    {

        process();

        /*output*/


        /*output*/
        answer = 0;
    }

    return 0;
}
