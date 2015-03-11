#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

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
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,(int)n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
bool pft[36000];
int MAX = sqrt(1000000000);
vi primes;
int a, b;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d %d ", &a, &b);
    return true;
}

long long num_divisors(long long num)
{
    /*
     *Long Longerestingly, if 40 has the prime factors (2^3 x 5^1),
     *the number of divisors it has is (3+1) x (1+1) == 8
     */ 

    long long ans = 1;
    long long pf_idx = 0;
    long long pf = primes[pf_idx];
    long long power;
    while (pf * pf <= num)
    {
        power = 0;
        while (num%pf == 0) { num /= pf; power++; }
        ans *= (power+1);
        pf = primes[++pf_idx];
        if (pf_idx == primes.size()) break;
    }
    if (num != 1) ans *= 2; // last factor^1 (+1)

    return ans;
}

void process()
{
    //process input
    int mx = 0;
    int tst;
    int num;
    FOR(i, a, b+1)
    {
        tst = num_divisors(i);
        if (mx < tst)
        {
            mx = tst;
            num = i;
        }
    }

    printf("Between %d and %d, %d has a maximum of %d divisors.\n", a, b, num, mx);
}

int main()
{
    CL(pft, 1);
    //sieve
    for (int i = 2; i <= MAX; ++i)
    {
        if (pft[i])
        {
            primes.push_back(i);
            for (int j = i*i; j <= MAX; j+=i)
                pft[j] = 0;
        }
    }
    
    int tc;
    scanf("%d ", &tc);
    while (tc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
