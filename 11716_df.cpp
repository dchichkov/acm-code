#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

#define DEBUG
//#undef DEBUG //uncomment this line to pull out print statements
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
string line;
char ciph_mat[110][110];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    getline(cin, line);
    return true;
}

void process()
{
    double mat = sqrt(line.length());
    //process input
    if (mat - (int)mat != 0)
        printf("INVALID");
    else
    {
        int ma = mat;
        int cur = 0;
        REP(i, ma)
        {
            REP(j, ma)
            {
                ciph_mat[i][j] = line[cur++];
            }
        }

        REP(i, ma)
        {
            REP(j, ma)
            {
                printf("%c", ciph_mat[j][i]);
            }
        }
    }
    printf("\n");
   
}

int main()
{
    CL2d(ciph_mat, 0, 110, 110);
    int nc;
    scanf("%d\n", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        CL2d(ciph_mat, 0, 110, 110);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
