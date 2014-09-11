#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <numeric>

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
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int m, n;
vi rules;
vi seats;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d %d ", &n, &m);
    if (!n && !m) return false;
    int a, b, c;
    REP(i, m)
    {
        scanf("%d %d %d ", &a, &b, &c);
        rules.push_back(a);
        rules.push_back(b);
        rules.push_back(c);
    }
    return true;
}

void process()
{
    //process input
    vi::iterator pos1, pos2;

    REP(i, n)
        seats.push_back(i);

    int x, y, dist;
    int counter = 0;
    bool bo;
    do
    {
        bo = true;
        REP(i, (int)rules.size())
        {
            x = rules[i]; y = rules[i+1]; dist = rules[i+2];
            pos1 = find(seats.begin(), seats.end(), x);
            pos2 = find(seats.begin(), seats.end(), y);
            if (dist < 0)
            {
                if (abs(pos1-pos2) < abs(dist))
                {
                    bo = false;
                    break;
                }
            }
            else
            {
                if (abs(pos1-pos2) > abs(dist))
                {
                    bo = false;
                    break;
                }
            }
                    
            i += 2;
        }
        if (bo) counter++;

    } while (next_permutation(seats.begin(), seats.end()));

    printf("%d\n", counter);
}

int main()
{
    while (getInput())
    {
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        seats.clear();
        rules.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
