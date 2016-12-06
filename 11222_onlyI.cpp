#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

#define DEBUG  //comment this line to pull out print statements
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
int friends[3][10002];
bool tie = true;
int biggest;
int maxa;
/*global variables*/

void dump()
{
    //dump data
    REP(i, 3)
    {
        printf("%d %d", i+1, friends[i][0]);
        for (int j = 1; friends[i][j] != -1; ++j)
        {
            if (friends[i][j] > 0)
                printf(" %d", j);
        }
        puts("");
    }
}

bool getInput()
{
    //get input
    CL2d(friends, 0, 3, 10001);
    int a, b, largestprob = 0;
    REP(i, 3)
    {
        largestprob = 0;
        scanf("%d ", &a);
        friends[i][0] = a;
        REP(j, a)
        {
            scanf("%d ", &b);
            friends[i][b] = 1;
            largestprob = max(largestprob, b);
        }
        friends[i][largestprob+1] = -1;
        maxa = max(friends[i][0], maxa);
    }
    
    return true;
}

void process()
{
    //process input
    dbg(
        cout << "dump:" << endl;
        dump();
        );
    REP(i, 3)
    {
        for (int j = 1; friends[i][j] != -1; ++j)
        {
            if (friends[(i+1)%3][j] > 0)
            {
                friends[(i+1)%3][j]--;
                friends[(i+1)%3][0]--;
            }
            if (friends[(i+2)%3][j] > 0)
            {
                friends[(i+2)%3][j]--;
                friends[(i+2)%3][0]--;
            }
        }
        if (friends[i][0] <  maxa)
        {
            tie = false;
            maxa = friends[i][0];
            biggest = i;
        }
    }
    debug(tie, endl);
    if (tie)
    {
        //print all
        REP(i, 3)
        {
            printf("%d %d", i+1, friends[i][0]);
            for (int j = 1; friends[i][j] != -1; ++j)
            {
                if (friends[i][j] != 0)
                    printf(" %d", j);
            }
            puts("");
        }
    }
    else
    {
        printf("%d %d", biggest+1, friends[biggest][0]);
        for (int j = 1; friends[biggest][j] != -1; ++j)
        {
            if (friends[biggest][j] != 0)
                printf(" %d", j);
        }
        puts("");
    }

}


int main()
{
    int nc, count = 0;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        printf("Case #%d:\n", ++count);
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        tie = true;
        biggest = 0;
        maxa = 0;
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
