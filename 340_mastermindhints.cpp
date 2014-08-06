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
map<int, int> solution, solution2;
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
    debug(num, endl);
    REP(i, num)
    {
        scanf("%d ", &n);
        solution[i] = n;
    }
    return true;
}

void process()
{
    //process input
    int n = 0, rp, wp;
    map<int, int>::iterator it;
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
        for (it = solution.begin(); it != solution.end(); ++it)
            solution2[it->first] = it->second;
        REP(i, num)
        {
            if (solution2[i] == guess[i])
            {
                rp++;
                solution2[i] = 0;
            }
        }
        REP(i, num)
        {
            if(solution2.find(guess[i]) != solution2.end())
            {
                wp++;
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
