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
int t, m, num_t;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d %d %d ", &m, &t, &num_t);
    if (t+m+num_t == 0) return false;
    return true;
}

void process()
{
    //process input
    int width = (t+m)*(num_t+1)-m;

    REP(i, num_t+1)
    {
        REP(j, t)
        {
            REP(k, width)
            {
                fputc('*', stdout);
            }
            puts("");
        }
        if (i != num_t)
        {
            REP(o, m)
            {
                REP(j, num_t+1)
                {
                    REP(k, t)
                    {
                        fputc('*', stdout);
                    }
                    if (j != num_t)
                    {
                        REP(k, m)
                        {
                            fputc('.', stdout);
                        }
                    }
                }
                puts("");
            }
        }

    }
    puts("");
}

int main()
{
    int count = 0;
    while (getInput())
    {
        printf("Case %d:\n", ++count);
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
