/*
  Thanks McKendon + Co-worker for guidance on the answer.


 */

#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>

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
string coins_left;
string coins_right;
string direction;

struct coin
{
    bool real;
    int value;
};

map<char, coin> coins;
/*global variables*/

void dump()
{
    //dump data
        
    for (map<char, coin>::iterator it = coins.begin(); it != coins.end(); it++)
    {
        debug(it->first, TAB); debug(it->second.real, TAB); debug(it->second.value, endl);
    }
}

bool getInput()
{
    //get input
    cin >> coins_left >> coins_right >> direction;
    return true;
}

void process()
{
    //process input
    char a;
    int i = 0, b = -100;
    int amt_ta = 0;
    do
    {
        getInput();
        debug(coins_left, TAB); debug(coins_right, TAB);debug(direction, endl);
        REP(j, coins_left.length())
        {
            amt_ta = (direction[0] == 'u') ? 1 : -1;
            if (coins.find(coins_left[j]) == coins.end())
            {
                if (direction[0] == 'e')
                {
                    coins[coins_left[j]];
                    coins[coins_left[j]].real = true;
                    coins[coins_left[j]].value = 0;
                }                    
                else
                {
                    coins[coins_left[j]];
                    coins[coins_left[j]].real = false;
                    coins[coins_left[j]].value = amt_ta;
                }
            }
            else
            {
                if (direction[0] == 'e')
                    coins[coins_left[j]].real = true;
                else if (!coins[coins_left[j]].real)
                    coins[coins_left[j]].value += amt_ta;
            }
        }

        REP(j, coins_right.length())
        {
            amt_ta = (direction[0] == 'u') ? -1 : 1;
            if (coins.find(coins_right[j]) == coins.end())
            {
                if (direction[0] == 'e')
                {
                    coins[coins_right[j]];
                    coins[coins_right[j]].real = true;
                    coins[coins_right[j]].value = 0;
                }                    
                else
                {
                    coins[coins_right[j]];
                    coins[coins_right[j]].real = false;
                    coins[coins_right[j]].value = amt_ta;
                }
            }
            else
            {
                if (direction[0] == 'e')
                    coins[coins_right[j]].real = true;
                else if (!coins[coins_right[j]].real)
                    coins[coins_right[j]].value += amt_ta;
            }
        }
    } while (i++ < 2);

    dbg(dump());
    
    for (map<char, coin>::iterator it = coins.begin(); it != coins.end(); it++)
    {
        if (!it->second.real && it->second.value > b)
        {
            b = it->second.value;
            a = it->first;
        }
    }

    
    printf("%c is the counterfeit coin and it is %s.\n", a, (b < 0) ? "light" : "heavy");
}

int main()
{
    int nc;
    scanf("%d\n", &nc);
    while (nc-- > 0)
    {
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        coins.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
