#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <list>

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
int buds[100020];
int nb, nr;
/*global variables*/

void dump()
{
    //dump data
    printf("%d", buds[0]);
    FOR(i, 1, nb)
        printf(" %d", buds[i]);        
}

bool getInput()
{
    //get input
    scanf("%d %d ", &nb, &nr);
    if (!nb && !nr) return false;

    return true;
}

void process()
{
    //process input
    REP(i, nb-1)
    {
        buds[i] = i+2;
    }
    buds[nb-1] = nb;
    int l, r, newb;
    bool ifd = false, ild = false;
    REP(i, nr)
    {
        scanf("%d %d ", &l, &r);
        if (r == nb){
            ild = true;
            newb = 0;
        }
        else
            newb = buds[r-1];

        if (l == 1) ifd = true;
        
        FOR(i, l-1, r-1)
        {
            buds[i] = newb;
        }

        if (ifd)
            printf("* ");
        else
            printf("%d ", l-1);
        if (newb == 0 && ild)
            printf("*");
        else
            printf("%d", buds[l-1]);
        dbg( puts(""); dump(););
        puts("");
    }
    printf("-\n");
}

int main()
{
    while (getInput())
    {
        CL(buds, 0);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
