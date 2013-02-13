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
const int sqmaxint = 50000;
unsigned int a, b;
vector<unsigned int> primes;
bool seive[sqmaxint];
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

void factor(unsigned int n, vector<unsigned int>& d)
{
    d.clear();
    for (int j = 0; (primes[j] <= n) && (j < primes.size()); ++j)
    {
        while (n%primes[j] == 0)
        {
            d.push_back(primes[j]);
            n /= primes[j];
        }
    }
}

void process()
{
    bool test = false;

    vector<unsigned int> du, dv;
    factor(a, du);

    if (a == 0) test = false;
    else if (((b == 0 || b == 1) && a == 1) || (a != 0 && b != 0 && a == b) || (a == 1) || (a < b)) test = true;
    else if (du.size() == 0) //prime
        test = false;
    else
    {
        for (int i = 2; (i <= b) && !test; ++i)
        {
            factor(i, dv);
            for (vector<unsigned int>::iterator jt = du.begin(); jt != du.end() && dv.size() != 0;)
            {
                vector<unsigned int>::iterator it = find(dv.begin(), dv.end(), *jt);
                if (it == dv.end())
                {
                    jt++;
                }
                else
                {
                    dv.erase(it);
                    du.erase(jt);
                }
            }
            if (du.size() == 0)
                test = true;
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
    
    bool moreToDo;
    while (moreToDo = getInput())
    {

        process();

        /*output*/


        /*output*/
    }
}
