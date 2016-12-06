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
const unsigned int MAX = 60000;
long long n;
bitset<MAX> bs;
vector<long long> primes;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%lld ", &n);
    if (n == 0) return false;
    return true;
}

void process()
{
    //process input

    printf("%lld =", n);

    bool first = false;
    if (n < 0)
    {
        printf(" -1");
        first = true;
    }
    n = abs(n);
    int PF = 0;
    while (n != 1)
    {

        while (n%primes[PF] == 0)
        {
            if (!first)
            {
                first = true;
                printf(" %lld", primes[PF]);
            }
            else
                printf(" x %lld", primes[PF]);
            n /= primes[PF];
        }
        PF++;
        if (PF == primes.size())
        {
            if (!first)
            {
                first = true;
                printf(" %lld", n);
            }
            else
                printf(" x %lld", n);
            break;
        }
    }
    puts("");
}

int main()
{
    bs.reset();
    bs[0] = 1;
    bs[1] = 1;
    for (long long i = 2; i < MAX+1; ++i)
    {
        if (!bs[i])
        {
            primes.push_back(i);
            for (long long j = i*i; j < MAX+1 && j > 0; j += i)
                bs[j] = 1;
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
