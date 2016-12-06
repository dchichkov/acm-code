#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <bitset>

using namespace std;

//#define DEBUG  //comment this line to pull out print statements
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
const int MAX_P = 100;
bitset<MAX_P> sieve;
int n;
vi primes;
int counter[100];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d ", &n);
    if (!n) return false;
    return true;
}

void process()
{
    //process input
    int t;
    FOR(i, 2, n+1)
    {
        t = i;
        for (int j = 0; primes[j] <= i && t != 1; ++j)
        {
            while (t % primes[j] == 0)
            {
                
                t /= primes[j];
                counter[primes[j]]++;
            }
        }
    }

    int omg = 0;
    printf("%3d! =", n);
    FOR(i, 2, 100)
    {
        if (counter[i] != 0)
        {
            if (omg && omg % 15 == 0)
                printf("\n      ");
            ++omg;
            dbg(cout << endl; );
            debug(counter[i], TAB); debug(i, endl);
            printf(" %2d", counter[i]);
        }
    }

    puts("");
}

int main()
{
    sieve[0] = 1;
    sieve[1] = 1;
    FOR(i, 2, MAX_P)
    {
        if (!sieve[i])
        {
            primes.push_back(i);
            for (int j = i*i; j < MAX_P; j += i)
                sieve[j] = 1;
        }
    }

    
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        CL(counter, 0);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
