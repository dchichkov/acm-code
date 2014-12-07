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
#define REP(i,n) FOR(i,0,(int)n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
char mat[11][11];
char mat2[11][11];
int n;
/*global variables*/

void dump()
{
    //dump data
    puts("");
    FOR(i, 1, n+1)
    {
        FOR(j, 1, n+1)
        {
            printf("%c", mat[i][j]);
        }
        puts("");
    }
    puts("");
    FOR(i, 1, n+1)
    {
        FOR(j, 1, n+1)
        {
            printf("%c", mat2[i][j]);
        }
        puts("");
    }
    puts("");
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;

    scanf("%d ", &n);
    FOR(i, 1, n+1)
    {
        FOR(j, 1, n+1)
        {
            scanf("%c ", &mat[i][j]);
        }
        FOR(j, 1, n+1)
        {
            scanf("%c ", &mat2[i][j]);
        }
    }
    return true;
}

void reflect()
{
    char temp[n+1][n+1];
    FOR(i, 1, n+1)
    {
        FOR(j, 1, n+1)
        {
            temp[n-i+1][j] = mat[i][j];
        }
    }
    FOR(i, 1, n+1)
    {
        FOR(j, 1, n+1)
        {
            mat[i][j] = temp[i][j];
        }
    }
}

void rotate()
{
    char temp[n+1][n+1];
    FOR(i, 1, n+1)
    {
        FOR(j, 1, n+1)
        {
            temp[j][n-i+1] = mat[i][j];
        }
    }
    FOR(i, 1, n+1)
    {
        FOR(j, 1, n+1)
        {
            mat[i][j] = temp[i][j];
        }
    }
}

bool check()
{
    FOR(i, 1, n+1)
    {
        FOR(j, 1, n+1)
        {
            if (mat[i][j] != mat2[i][j])
                return false;
        }
    }
    return true;
}

void process()
{
    //process input
    int cnt = 0;
    REP(i, 4)
    {
        if (check()) break;
        rotate();
        dbg(dump(););
        cnt++;
    }
    if (cnt == 0)
        printf("preserved.");
    else if (cnt == 4)
    {
        cnt = 0;
        reflect();
        if (check())
            printf("reflected vertically.");
        else
        {
            REP(i, 4)
            {
                cnt++;
                rotate();
                if (check()) break;
                dbg(dump(););
            }
            if (cnt == 4)
                printf("improperly transformed.");
            else
                printf("reflected vertically and rotated %d degrees.", cnt*90);
        }
    }
    else
        printf("rotated %d degrees.",cnt*90);
    puts("");
        
}

int main()
{
    int nc = 0;
    while (getInput())
    {
        printf("Pattern %d was ", ++nc);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        CL2d(mat, 0, 11, 11);
        CL2d(mat2, 0, 11, 11);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
