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
int N;
int arr[110][110];
/*global variables*/

void dump()
{
    //dump data
    FOR(i, 1, N)
    {
        FOR(j, 1, N)
        {
            printf("%d ", arr[i][j]);
        }
        cout << endl;
    }
}

bool getInput()
{
    //get input
    scanf("%d", &N);
    N+=1;
    FOR(i, 1, N)
    {
        FOR(j, 1, N)
        {
            scanf("%d", &arr[i][j]);
            arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    }
    return true;
}

void process()
{
    //process input
    int maxSubRect = -127*100*100, subRect = 0;
    FOR(i, 1, N)
    {
        FOR(j, 1, N)
        {
            FOR(k, i, N)
            {
                FOR(l, j, N)
                {
                    subRect = arr[k][l];
                    subRect = subRect - arr[i-1][l] - arr[k][j-1] + arr[i-1][j-1];
                    maxSubRect = max(subRect, maxSubRect);
                }
            }
        }
    }

    cout << maxSubRect << endl;
}

int main()
{
    CL2d(arr, 0, 110, 110);
    while (getInput())
    {

        process();
        break;
        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
