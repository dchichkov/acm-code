#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>

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
const int MAX_NUM = 50000;
long sols[MAX_NUM+1];
int highest = 2;
int num = 0;
bool is_prime[MAX_NUM+1];
vi primes;
/*global variables*/

void dump()
{
    //dump data
    for (int i = 0; i < primes.size(); ++i)
        debug(primes[i], endl);
}

bool getInput()
{
    //get input
    scanf("%d", &num);
    if (!num) return false;
    return true;
}

void do_sieve()
{
    memset(is_prime, 1, sizeof(is_prime)); //initialize all as true
    for (long long i = 2; i <= MAX_NUM; ++i)
    {
        if (is_prime[i])
        {
            for (long long j = i*i; j <= MAX_NUM; j += i)
            {
                is_prime[j] = 0;
            }
            primes.push_back(i);
        }
    }
}

int64 EulerPhi(int64 N)
{
    int64 prime_factor_indx = 0, pf = primes[prime_factor_indx], ans = N;
    while ( N != 1 && (pf * pf <= N))
    {
        if ( N % pf == 0) ans -= ans / pf;
        while ( N % pf == 0 )  N /= pf;
        pf = primes[++prime_factor_indx];
    }
    if ( N != 1 ) ans -= ans / N;
    return ans;
}

void process()
{
    //process input
    debug(num, TAB); debug(highest, endl);
    if (num > highest)
    {
        debug(num, endl);
        for (; highest <= num; ++highest)
        {
            debug(highest, endl);
            sols[highest] = EulerPhi(highest)*2 + sols[highest-1];
        }
        --highest; //because the for loop increments this
    }

    printf("%ld\n", sols[num]);
}

int main()
{
    do_sieve();
    sols[1] = 1;
    sols[2] = 3;
    bool moreToDo;
    while (moreToDo = getInput())
    {
        //debug(num, endl);
        process();

        /*output*/


        /*output*/
    }
}
