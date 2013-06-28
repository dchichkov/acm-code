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
string S1, S2;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    getline(cin, S1);
    getline(cin, S2);
    return true;
}

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a%b);
}

void process()
{
    //process input
    //convert each to decimal
    int a = 0, b = 0;
    int mul = S1.length() - 1;
    REP(i, S1.length())
    {
        a |= (S1[i]-'0'<<(mul--));
    }
    mul = S2.length()-1;
    REP(i, S2.length())
    {
        b |= (S2[i]-'0'<<(mul--));
    }

    printf("%s\n", gcd(a, b) != 1 ? "All you need is love!" : "Love is not all you need!");
}

int main()
{
    int nc, count = 1;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        printf("Pair #%d: ", count++);
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
