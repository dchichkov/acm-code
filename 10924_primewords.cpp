#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <cctype>

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
bitset<1050> primes;
char line[50];
/*global variables*/



void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    fgets(line, 50, stdin);
    scanf(" ");
    return true;
}

void process()
{
    //process input
    int num = 0;
    if (line[strlen(line)-1] == '\n')
        line[strlen(line)-1] = 0;
    REP(i, strlen(line))
    {
        if (isupper(line[i]))
        {
            num += line[i]-0x40+26;
        }
        else
        {
            num += line[i]-0x60;
        }
    }
    debug(num, endl);
    printf("It is %sa prime word.\n", primes[num] ? "" : "not ");
}

int main()
{
    //sieve
    primes.set();
    primes[0] = 0;

    for (int i = 2; i <= 1050; ++i)
    {
        if (primes[i])
        {
            for (int j = i*i; j <= 1050; j += i)
                primes[j] = 0;
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
