/* Class:   CSC 2700 Programming Competitions
 * Prof:    Isaac Traxler
 * Name:    Matthew Gavin
 * Problem: 11292 - Dragon of Loowater
 *
 */ 


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

vi dragon_heads;
vi knight_height;

/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int num_heads, num_knights;
    scanf("%d %d ", &num_heads, &num_knights);
    if (num_heads == 0 && num_knights == 0) return false;
    int t;
    REP(i, num_heads)
    {
        scanf("%d ", &t);
        dragon_heads.push_back(t);
    }
    REP(i, num_knights)
    {
        scanf("%d ", &t);
        knight_height.push_back(t);
    }
    
    return true;
}

void process()
{
    //process input
    sort(knight_height.begin(), knight_height.end());
    sort(dragon_heads.begin(), dragon_heads.end());

    vi::iterator j = knight_height.begin(), i = dragon_heads.begin();

    int amt = 0;
    for (; i < dragon_heads.end();)
    {
        for (; j < knight_height.end(); ++j)
        {
            if (*i <= *j)
            {
                amt += *j;
                ++j;
                ++i;
                break;
            }
        }
        if (j == knight_height.end()) break;
    }

    if (i == dragon_heads.end())
        printf("%d", amt);
    else
        printf("Loowater is doomed!");

    printf("\n");
    
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        dragon_heads.clear();
        knight_height.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
