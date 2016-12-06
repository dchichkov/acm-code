#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
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
vi solution, solution2;
vi guess;
int num;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int n;
    scanf("%d ", &num);
    if (num == 0)
        return false;
    //debug(num, endl);
    REP(i, num)
    {
        scanf("%d ", &n);
        solution.push_back(n);
    }
    return true;
}

void process()
{
    //process input
    int n = 0, rp, wp;
    solution2.resize(solution.size());
    while (true)
    {
        guess.clear();
        REP(i, num)
        {
            scanf("%d ", &n);
            if (n == 0)
            {
                FOR(j, i+1, num)
                {
                    scanf("%d ", &n);
                }
                break;
            }
            else
                guess.push_back(n);
        }
        if (guess.empty()) break;
        rp = wp = 0;

        copy(solution.begin(), solution.end(), solution2.begin());
        REP(i, num)
        {
            if (solution2[i] == guess[i])
            {
                rp++;
                solution2[i] = -1;
                guess[i] = -1;
            }
        }
        vi::iterator it;
        REP(i, num)
        {
            if (guess[i] == -1) continue;
            it = find(solution2.begin(), solution2.end(), guess[i]);
            if(it != solution2.end())
            {
                wp++;
                *it = -1;
            }
        }
        if (n) printf("    (%d,%d)\n", rp, wp);
    }
}

int main()
{
    int count = 0;
    while (getInput())
    {
        printf("Game %d:\n", ++count);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        solution.clear();
        guess.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
