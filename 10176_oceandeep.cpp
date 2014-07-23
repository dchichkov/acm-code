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
string num;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    char c = 0;
    scanf("%c ", &c);
    while (c != '#')
    {
        num += c;
        scanf("%c ", &c);
    }
    return true;
}

bool ismod131071(unsigned long long hmm)
{
    return ((hmm % 131071) == 0);
}

void process()
{
    //process input
    unsigned long long idk = 0;
    REP(i, num.length())
    {
        idk += (pow(2, i) * (num[num.length()-i-1] - 0x30));
        if (ismod131071(idk)) break;
    }

    if (ismod131071(idk)) printf("YES");
    else printf("NO");

    puts("");
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        num.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
