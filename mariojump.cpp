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
#else
#define debug(a, end)
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
int high, low;
int n;

int main()
{
    int num_cases;
    int dist, count, dist2;
    scanf("%d", &num_cases);
    while (num_cases-- > 0)
    {
        scanf("%d", &n);
        scanf("%d", &dist);
        for (int i = 0; i < n-1; ++i)
        {
            scanf("%d", &dist2);
            if (dist < dist2) high++;
            else if (dist > dist2) low++;
            dist = dist2;
        }

        printf("Case %d: %d %d\n", ++count, high, low);

        dist = dist2 = high = low = 0;
    }

    return 0;
}
