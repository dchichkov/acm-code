#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

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
vi north, south;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int nr;
    scanf("%d ", &nr);
    int t, u;
    REP(i, nr)
    {
        
        scanf("%d %d ", &t, &u);
        north.push_back(t);
        south.push_back(u);
    }
    
    return true;
}

void process()
{
    //process input

    bool cando = false;

    while (true)
    {
        //check
        for (int i = 0; i < north.size(); ++i)
        {
            if (north[i] == south[i]) cando = true;
            else if (cando)
            {
                cando = false;
                goto done;
            }
        }
        if (cando) break;
        //subtract 1 from north each time
        for (int i = 0; i < north.size(); ++i)
            north[i]--;
    }
done:
    printf("%s\n", (cando) ? "yes" : "no");
}

int main()
{
    int nc;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();
        if (nc != 0) printf("\n");
        /*CLEAR GLOBAL VARIABLES!*/
        north.clear();
        south.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
