/* Class:   CSC 2700 Programming Competitions
 * Prof:    Isaac Traxler
 * Name:    Matthew Gavin
 * Problem: 1210 - Sum of Consecutive Prime Numbers
 *
 * Note: I only saw Son's initial comment I swear! Then I was determined
 *       to try to get a linear solution... and even though I suck at
 *       orders of magnitude.. I would think this is O(n * num of primes to n)??
 *       which is better than O(n^2)? But that's just a guess and hopefully when I'm
 *       30 I can prove it :P
 *
 */

#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

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
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/

int num;
int prime[10001];
int precmp[10001];
vi primes;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d ", &num);
    if (num == 0) return false;
    return true;
}

void sieve()
{
    int t = 0;
    for (int i = 2; i < 10001; ++i)
    {
        if (prime[i])
        {
            for (int j = i+i; j < 10001; j+=i)
                prime[j]=0;

            primes.push_back(i);
            t = 0;
            for (vi::reverse_iterator rit = primes.rbegin(); rit != primes.rend(); ++rit)
            {
                t += *rit;

                if (t < 10001)
                {
                    precmp[t]++;
                }
                else break;
            }
        }
    }
}


void process()
{
    printf("%d\n", precmp[num]);
}

int main()
{
    memset(prime, 1, sizeof(prime));
    memset(precmp, 0, sizeof(precmp));
    sieve();
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
