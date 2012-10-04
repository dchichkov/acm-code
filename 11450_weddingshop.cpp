#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

#define DEBUG
#undef DEBUG //uncomment this line to pull out print statements
#ifdef DEBUG
#define TAB '\t'
#define debug(a, end) cout << #a << ": " << a << end
#define dbg(end) end
#else
#define debug(a, end)
#define dbg(end)
#endif

typedef pair<int, int> point;
typedef long long int64; //for clarity
typedef vector<int> vi; //?
typedef vector<point> vp; //?
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } //change min
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } //change max

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int memo[215][25]; //OMG DYNAMIC PROGRAMMING
int M, C;
/*global variables*/

void dump()
{
    //dump data
    REP(i, M)
    {
        cout << i << ": | ";
        REP(j, C)
        {
            cout << memo[i][j] << " | ";
        }
        cout << endl;
    }
}

bool getInput()
{
    //get input
    scanf("%d %d", &M, &C);
    debug(M, TAB); debug(C, endl);
    int c, x;
    //BOTTOM-UP
    {
        scanf("%d", &c);
        debug(c, TAB);
        REP(j, c)
        {
            scanf("%d", &x);
            debug(x, TAB);
            if (M >= x)
                memo[M-x][0] = 1;
        }
        dbg(cout << endl);
    }

    FOR(i, 1, C) //BOTTOM-UP
    {
        scanf("%d", &c);
        debug(c, TAB);
        REP(j, c)
        {
            scanf("%d", &x);
            debug(x, TAB);
            REP(k, M-x)
            {
                if (memo[k+x][i-1]) memo[k][i] = 1;
            }
        }
        dbg(cout << endl);
    }
    return true;
}

void process()
{
    dbg(dump());
    bool possible = false;
    //process input
    REP(i, 201)
    {
        if (memo[i][C-1])
        {
            possible = true;
            printf("%d\n", M-i);
            break;
        }
    }
    if (!possible) printf("no solution\n");
}

int main()
{
    CL2d(memo, 0, 210, 21);
    int nc;
    scanf("%d", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        CL2d(memo, 0, 210, 21);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
