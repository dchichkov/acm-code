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

struct uh
{
    string s;
    int score;
};

/*global variables*/
uh what[10];
/*global variables*/

int main()
{
    int num_cases = 0;
    int count = 0;
    char url[200]; int maxs = 0, score;
    scanf("%d", &num_cases);
    while (num_cases-- > 0)
    {
        REP(i, 10)
        {
            scanf("%s %d", url, &score);
            maxs = max(maxs, score);
            what[i].s = url;
            what[i].score = score;
        }
        printf("Case #%d:\n", ++count);
        REP(i, 10)
        {
            if (what[i].score == maxs)
                printf("%s\n", what[i].s.c_str());
        }
        maxs = 0;
    }

    return 0;
}
