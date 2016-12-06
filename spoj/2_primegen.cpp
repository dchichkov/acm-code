#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <fstream>

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
bitset<31630> nms;
vi primes;
int x, y;
//fstream in("2_primegen.out");
/*global variables*/

void sieve(int a, int b)
{
    /*int c;
    while (!in.eof())
    {
        in >> c;
        primes2.push_back(c);
        }*/
    
    nms.set();
    nms[0] = nms[1] = 0;
    for (int i = a; i < b+1; ++i)
    {
        if (nms[i])
        {
            primes.push_back(i);
            for (int j = i*i; j < b+1; j += i)
                nms[j] = 0;
        }
    }
}

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d %d ", &x, &y);
    return true;
}

void process()
{
    //process input

    double sqri;
    dbg( int cnt = 0; );
    FOR(i, x, y+1)
    {
        if (i < 31630)
        {
            if (nms[i])
            {
                printf("%d\n", i);
                //cnt++; if (cnt % 10 == 0) puts("");
            }
            continue;
        }
        sqri = sqrt(i);
        for (int j = 0; j < (int)primes.size() && primes[j] <= sqri; ++j)
        {
            if (i % primes[j] == 0)
                goto next;
        }
        /*if (find(primes2.begin(), primes2.end(), i) == primes2.end())
          debug(i, endl);*/
        printf("%d\n", i);
        //cnt++; if (cnt % 10 == 0) puts("");
    next:
        ;
    }
}

int main()
{
    int nc;
    scanf("%d ", &nc);
    sieve(2, 31630);
    while (nc-- > 0)
    {
        getInput();
        process();
        if (nc != 0) puts("");
        /*CLEAR GLOBAL VARIABLES!*/
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
