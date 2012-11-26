#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <set>
#include <algorithm>
#include <numeric>

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
string line;
int times[10];
int tc = 0;

vi primes;
/*global variables*/

void sieve()
{
    int pr[101];
    memset(pr, 0, 101*sizeof(int));
    for (int i = 2; i < 101; ++i)
    {
        if (!pr[i])
        {
            primes.push_back(i);
            for (int j = i+i; j < 101; j+=i)
                pr[j] = 1;
        }
    }
}

void dump()
{
    //dump data
    REP(i, tc)
        debug(times[i], TAB);
    dbg(cout << endl);
    REP(i, primes.size())
        debug(primes[i], endl);
}

bool getInput()
{
    //get input
    if (cin.eof()) return false;
    getline(cin, line);
    if (line.length() == 0) return false;
    istringstream s(line);

    while (!s.eof()) { s >> times[tc]; tc++; }
    return true;
}

void process()
{
    //process input
    //dbg(dump());
    int ttime = 0;
    set<int> prf;
    REP(i, tc)
    {
        REP(j, primes.size())
        {
            if (times[i] % primes[j] == 0) prf.insert(primes[j]);
        }
    }
    set<int> tt;
    REP(i, tc)
        tt.insert(times[i]);

    ttime = 1;
    for (set<int>::iterator it = prf.begin(); it != prf.end(); ++it)
        ttime *= *it;
    ttime += accumulate(tt.begin(), tt.end(), 0);
    debug(ttime, endl);
    dbg(
        for (set<int>::iterator it = prf.begin(); it != prf.end(); ++it)
            debug(*it, TAB);
        cout << endl;
        for (set<int>::iterator it = tt.begin(); it != tt.end(); ++it)
            debug(*it, TAB);
        cout << endl;
        );
        
    if (ttime <= 3600)
        printf("synchs again at %d minute(s) and %d second(s) after all turning green.\n", ttime/60, ttime%60);
    else
        printf("is unable to synch after one hour.\n");
               
}

int main()
{
    sieve();

    int count = 0;
    while (getInput())
    {
        printf("Set %d ", ++count);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        CL(times, 0);
        tc = 0;
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
