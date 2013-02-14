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
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
const unsigned int sqmaxint = 50000;
unsigned int a, b;
vector<unsigned int> primes;
bool seive[sqmaxint];
int du[sqmaxint];
int dv[sqmaxint];
int tot;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    scanf("%u %u ", &b, &a);
    return true;
}

int factor(unsigned int n, int* arr, unsigned int* lp)
{
    int i, j;
    int tot2 = 0;
    for (i = 0, j = 0; (primes[j] <= n) && (j < primes.size()); ++j)
    {
        while (n%primes[j] == 0)
        {
            arr[primes[j]]++;
            n /= primes[j];
            i = j;
            tot2++;
        }
    }
    tot = max(tot, tot2);
    if (lp != NULL) *lp = n;
    return primes[i];
}

void process()
{
    bool test = false;
    unsigned int lp = 0;
    unsigned int mm = min(b, primes.back());
    int maxm = factor(a, du, &lp), maxn;
    if (a == 0) test = false;
    else if (((b == 0 || b == 1) && a == 1) || (a != 0 && b != 0 && a == b) || (a == 1) || (a < b)) test = true;
    else if (find(primes.begin(), primes.end(), a) != primes.end()) //prime
        test = false;
    else if (lp > b) test = false;
    else
    {
        //debug(maxm, endl);
        for (int i = 2; (i < mm) && !test; ++i)
        {
            test = true;
            factor(i, dv, NULL);
            //debug(maxm, endl);
            FOR(k, 2, maxm+1)
            {
                if (du[k] == 0) continue;
                du[k] -= dv[k];
                //debug(maxm, TAB); debug(k, TAB); debug(du[k], TAB); debug(dv[k], endl);
                dv[k] = 0;
                if (du[k] > 0) { test = false; maxn = k+1; }
            }
            maxm = maxn;
        }
    }
    if (test)
        cout << a << " divides " << b << "!" << endl;
    else
        cout << a << " does not divide " << b << "!" << endl;
}

int main()
{
    memset(seive, 1, sizeof(seive)); //set true

    for (unsigned int i = 2; i <= sqmaxint; ++i)
    {
        if (seive[i])
        {
            primes.push_back(i);
            for (unsigned int j = i+i; j <= sqmaxint; j += i)
            {
                seive[j] = 0;
            }
        }
    }
    debug(primes.size(), endl);
    bool moreToDo;
    while (moreToDo = getInput())
    {

        process();

        /*output*/
        //debug(tot, endl);
        tot = 0;
        CL(du, 0);
        CL(dv, 0);
        /*output*/
    }
}
