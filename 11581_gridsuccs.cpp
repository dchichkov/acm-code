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
int matrix[5][5];
int hashes[512];
int idx;

int xs[] = {0, -1, 0, 1};
int ys[] = {1, 0, -1, 0};
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    CL2d(matrix, 0, 5, 5);

    char num;
    FOR(i, 1, 4)
    {
        FOR(j, 1, 4)
        {
            scanf("%c ", &num);
            matrix[i][j] = num-0x30;
        }
    }

    dbg(
        FOR(i, 1, 4)
        {
            FOR(j, 1, 4)
            {
                printf("%d", matrix[i][j]);
            }
            puts("");
        }
        puts("");
        );
    
    return true;
}

void f()
{
    //teehee
    int matrix2[5][5];
    CL2d(matrix2, 0, 5, 5);
    dbg(cout << "ran f()" << endl);
    int total;
    FOR(i, 1, 4)
    {
        FOR(j, 1, 4)
        {
            total = 0;
            for (int k = 0; k < 4; ++k)
            {
                total += matrix[i+ys[k]][j+xs[k]];
            }
            matrix2[i][j] = total%2;
        }
    }

    FOR(i, 1, 4)
    {
        FOR(j, 1, 4)
        {
            matrix[i][j] = matrix2[i][j];
        }
    }
}

bool hashandcheck()
{
    int num = 0;
    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            debug(matrix[i][j], TAB); debug(((i-1)*3 + (j-1)), endl);
            num |= (matrix[i][j] << (8 - ((i-1)*3 + (j-1))));
        }
    }

    debug(num, TAB); dbg( printf("num(hex) %X\n", num); );
    if (!hashes[num])
    {
        hashes[num] = 1;
        idx += 1;
        return false;
    }
    else
    {
        if (num != 0)
            idx = -1;
        return true;
    }
}

void process()
{
    //process input
    bool b;
    idx = -1;
    while ( !(b = hashandcheck()) )
    {
        f();
    }
    printf("%d\n", idx);
    
    dbg(
        FOR(i, 1, 4)
        {
            FOR(j, 1, 4)
            {
                printf("%d", matrix[i][j]);
            }
            puts("");
        }
        puts("");
        );
}

int main()
{
    int nc;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        CL(hashes, 0);
        hashes[0] = 1;
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
