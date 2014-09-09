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
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int n;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d ", &n);
    return true;
}

void process()
{
    //process input
    string str1;
    if (abs(n)%2) { n--; str1.insert(0, "1"); }
    if (n == 0) str1 = "0";
    for (int i = 0; i < 20 && n != 0; ++i)
    {
        if (n >= pow(-2, i))
        {
            //sp = true;
            n -= abs(pow(-2, i));
            str1.insert(0, "1");
        }
        else str1.insert(0, "0");
    }
    printf("%s", str1.c_str());
    puts("");
}

int main()
{
    int nc, cnt = 0;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        printf("Case #%d: ", ++cnt);
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
