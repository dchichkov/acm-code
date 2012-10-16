#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>


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
#define FOR(i,a,b) for (int  i = (a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int N;
bool primes[20];
vector<int> ring;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin) ||
        scanf("%d", &N) == EOF) return false;

    REP(i, N)
    {
        ring.push_back(i+1);
    }
    
    return true;
}

void process()
{
    int a[1];
    bool primal = true;
    do
    {
        FOR(i, 1, N-1)
        {
            if (!primes[ring[i] + ring[i-1]] || !primes[ring[i] + ring[i+1]])
            {
                primal = false;
                break;
            }
        }

        if (primal && primes[ring[0] + ring[N-1]])
        {
            printf("%d", ring[0]);
            FOR(i, 1, N)
                printf(" %d", ring[i]);
            
            printf("\n");
        }
        primal = true;
    }
    while (next_permutation(ring.begin()+1, ring.end()));

    printf("\n");      
}

int main()
{

    CL(primes, 0);
    
    primes[3] = true;
    primes[5] = true;
    primes[7] = true;
    primes[11] = true;
    primes[13] = true;
    primes[17] = true;
    primes[19] = true;
    
    int count = 0;
    while (getInput())
    {
        printf("Case %d:\n", ++count);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        ring.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
