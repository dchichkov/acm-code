#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>

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
#define REP(i,n) FOR(i,0,(int)n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int num;
map<long long, bool> prevv;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d ", &num);
    return true;
}

void process()
{
    //process input
    long S1 = 0;
    long long nnum = num, nn2;
    char c;
    while (S1 != 1 && S1 != num)
    {
        S1 = 0;
        while (nnum != 0)
        {
            nn2 = nnum%10;
            S1 += nn2 * nn2;
            nnum /= 10;
        }
        nnum = S1;
        if (prevv[nnum]) break;

        prevv[nnum] = true;
    }
    printf("%d is a%s number.\n", num, nnum == 1 ? " Happy" : "n Unhappy");
}

int main()
{
    int nc;
    scanf("%d ", &nc);
    int count = 1;
    while (nc-- > 0)
    {
        printf("Case #%d: ", count++);
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        prevv.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
