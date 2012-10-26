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
vi primes;
long long N;
/*global variables*/

void dump()
{
    //dump data
}

void sieve()
{
    vector<bool> prime(10000000, true);

    for (long long i = 2; i < 10000000; ++i)
    {
        if (prime[i])
        {
            for (long long j = i*i; j < 10000000; j += i)
                prime[j] = false;
            primes.push_back(i);
        }
    }
}

bool getInput()
{
    //get input
    scanf("%lld", &N);
    if (N == 0) return false;
    return true;
}

void process()
{
    //process input
    long long maxi = 0;
    for (int i = 0; i < primes.size() && primes[i] <= ((long long)sqrt(N)+1); ++i)
    {
        if (N % primes[i] == 0)
        {
            if (N == primes[i])
                break;
            maxi = max(maxi, primes[i]);
        }
    }

    if (!maxi)
        printf("-1");
    else
        printf("%lld", maxi);

    printf("\n");
}

int main()
{
    sieve();
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
