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
int L;
int train[50];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    
    scanf("%d", &L);
    REP(i, L)
        scanf("%d", &train[i]);
    return true;
}

void process()
{
    //process input
    int count = 0;
    //bubble sort, with A[1..i] sorted, and A[1..i] < A[i+1..j]
    REP(i, L)
    {
        for (int j = L-1; j > i; --j)
        {
            if (train[j] < train[j-1])
            {
                swap(train[j], train[j-1]);
                count++;
            }
        }
    }

    printf("Optimal train swapping takes %d swaps.\n", count);
}

int main()
{
    int nc;
    scanf("%d", &nc);
    
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
