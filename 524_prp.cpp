#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

//#define DEBUG
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
bool primes[35];
bool f;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (scanf("%d ", &N) == EOF) return false;
    if (f) puts("");
    else f = !f;
    
    return true;
}

void iterate(vi rng, int n)
{
    debug(rng.size(), TAB); debug(n, endl);
    if (primes[rng.back() + n])
    {
        rng.push_back(n);
    }
    else return;
    if (rng.size() == N && primes[rng.back() + rng.front()])
    {
        //output
        printf("%d", rng[0]);
        FOR(i, 1, rng.size())
        {
            printf(" %d", rng[i]);
        }
        puts("");
        return;
    }

    FOR(i, 2, N+1)
    {
        if (find(rng.begin(), rng.end(), i) == rng.end())
            iterate(rng, i);
    }
        
}

void process()
{
    if (N % 2 == 1) { return; }
    vi ring;
    set<int> lft;
    ring.push_back(1);
    //FOR(i, 2, N+1)
    //    lft.insert(i);
    FOR(i, 2, N+1)
    {
        iterate(ring, i);//, lft);
    }
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
    primes[23] = true;
    primes[29] = true;
    primes[31] = true;
    
    int count = 0;
    while (getInput())
    {
        printf("Case %d:\n", ++count);
        process();
        
        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
