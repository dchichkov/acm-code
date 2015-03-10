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
int totaltime;
vi lens;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int nl, a;
    if (feof(stdin)) return false;
    scanf("%d %d ", &totaltime, &nl);
    REP(i, nl)
    {
        scanf("%d ", &a);
        lens.push_back(a);
    }
    return true;
}

void process()
{
    vi lens2(lens);
    sort(lens.begin(), lens.end(), std::less<int>());
    //process input
    int sum;
    vi ans;
    int closest = totaltime;
    for (int i = 0; i < (1<<(int)lens.size()); ++i)
    {
        sum = 0;
        for (int j = 0; j < (int)lens.size(); ++j)
            if (i & (1<<j))
                sum += lens[j];
        
        if (totaltime-sum >= 0 && totaltime-sum < closest)
        {
            debug(totaltime-sum, endl);
            ans.clear();
            closest = totaltime-sum;
            for (int j = 0; j < (int)lens.size(); ++j)
                if (i & (1<<j))
                    ans.push_back(lens[j]);
        }
        if (sum == totaltime) break;
    }

    REP(i, (int)lens2.size())
    {
        if (find(ans.begin(), ans.end(), lens2[i]) != ans.end())
            printf("%d ", lens2[i]);
    }

    printf("sum:%d\n", totaltime-closest);

}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        lens.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
