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
int grade;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    grade = 0;
    vi tests;
    int a;
    REP(i, 7)
    {
        scanf("%d ", &a);
        if (i >= 4)
            tests.push_back(a);
        else
            grade += a;
    }
    SORT(tests);
    grade += ((tests[2] + tests[1]) / 2);
    
    return true;
}

void process()
{
    //process input
    if (grade >= 90)
        printf("A");
    else if (grade >= 80)
        printf("B");
    else if (grade >= 70)
        printf("C");
    else if (grade >= 60)
        printf("D");
    else printf("F");
    puts("");
}

int main()
{
    int count = 0, nc;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        printf("Case %d: ", ++count);
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
