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
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
const int MAX_N = 100010;
char T[MAX_N], P[MAX_N];
int b[MAX_N], n, m, num_in;

/*global variables*/

void kmpPreprocess()
{
    int i = 0, j = -1; b[0] = -1;
    while (i < m)
    {
        while (j >= 0 && P[i] != P[j]) j = b[j];
        ++i; ++j;
        b[i] = j;
    }
}

void kmpSearch()
{
    int i = 0, j = 0;
    while (i < n)
    {
        while (j >= 0 && T[i] != P[j]) j = b[j];
        ++i; ++j;
        if (j == m)
        {
            printf("y\n");
            return;
        }
    }
    printf("n\n");
}

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    fgets(T, MAX_N, stdin);
    if (T[strlen(T)-1] == '\n') T[strlen(T)-1] = 0;
    scanf("%d ", &num_in);
    n = strlen(T);
    debug(T, TAB);
    debug(num_in, endl);
    return true;
}

bool isPrefix()
{
    bool ok;
    REP(i, strlen(T))
    {
        if (T[i] == P[i])
        {
            ok = true;
            FOR(j, 1, strlen(P))
            {
                if (T[i+j] == P[j] && ok)
                    ok = true;
                else
                    ok = false;
            }
        }
        if (ok)
            break;
    }
    return ok;
}

void process()
{
    //process input
    REP(i, num_in)
    {
        fgets(P, 1001, stdin);
        if (P[strlen(P)-1] == '\n') P[strlen(P)-1] = 0;
        m = strlen(P);
        debug(P, endl);
        //kmpPreprocess();
        //kmpSearch();
        printf("%s\n", isPrefix() ? "y" : "n");
    }
}

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        CL(b, 0);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
