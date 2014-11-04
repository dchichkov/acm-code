#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <bitset>

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
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
#define MAX_S 1000010
int n;
bitset<MAX_S> sieve;
vi primes;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d ", &n);
    if (n == 0) return false;
    return true;
}

void process()
{
    //process input
    int b, a;
    int i;
    for (i = 0; primes[i] < n; ++i)
    {
        b = primes[i];
        for (int j = 0; j < i; ++j)
        {
            if (b + primes[j] < n) continue;
            if (b + primes[j] > n) break;
            
            if (b + primes[j] == n)
            {
                a = primes[j];
                goto done;
            }
        }
    }

done:
    if (primes[i] > n)
        printf("Goldbach's conjecture is wrong.");
    else
        printf("%d = %d + %d", n, a, b);
    puts("");
}

int main()
{
    //precompute
    sieve[0] = 1;
    sieve[1] = 1;
    FOR(i, 2, MAX_S)
    {
        if (sieve[i] == 0)
        {
            primes.push_back(i);
            for (int j = i*i; 2 < j && j <= MAX_S; j += i)
            {
                sieve[j] = 1;
            }
        }
    }
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
