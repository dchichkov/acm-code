#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

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
int n;
int matrix[110][110];
/*global variables*/

void dump()
{
    //dump data
    REP(i, n)
    {
        REP(j, n)
            cout << matrix[i][j];
        cout << endl;
    }
}

bool par_row(int row)
{
    int t = 0;
    debug(row, TAB);
    REP(i, n)
    {
        debug(i, TAB);
        t += matrix[row][i];
        debug(matrix[row][i], endl);
    }
    dbg(cout << "row" << "\t");
    debug(t, endl);
    return (!(t%2));
}

bool par_col(int col)
{
    int t = 0;
    REP(i, n)
    {
        t += matrix[i][col];
    }
    dbg(cout << "col" << "\t");
    debug(t, endl);
    return (!(t%2));
}

bool check_par()
{

    REP(i, n)
        if (!par_row(i))
            return false;

    REP(i, n)
        if (!par_col(i))
            return false;
    return true;
}

bool getInput()
{
    //get input
    scanf("%d", &n);
    if (n == 0) return false;
    REP(i, n)
    {
        REP(j, n)
            scanf("%d", &matrix[i][j]);
    }
    dbg(dump());
    return true;
}

void process()
{
    //process input
    bool is_par = check_par();
    if (!is_par)
    {
        REP(i, n)
        {
            REP(j, n)
            {
                matrix[i][j] = !matrix[i][j];
                is_par = check_par();
                if (is_par)
                {
                    printf("Change bit (%d,%d)\n", i+1, j+1);
                    goto end;
                }
                matrix[i][j] = !matrix[i][j];
            }
        }
        printf("Corrupt\n");        
    }
    else
        printf("OK\n");
 end:
    ;
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        CL(matrix, 0);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
