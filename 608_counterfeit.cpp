#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>

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

map<char, char> coins;
/*global variables*/

void dump()
{
    for (map<char, char>::iterator it = coins.begin(); it != coins.end(); it++)
    {
        debug(it->first, TAB); debug(it->second, endl);
    }
    
    //dump data
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
    char a, b, dir;
    int i = 0;

    do
    {
        REP(j, coins_left.length())
        {
            dir = (direction[0] == 'u') ? 'd' : 'u';
            dir = (direction[0] == 'e') ? 'e' : dir;
            if (coins.find(coins_left[j]) == coins.end())
            {
                coins[coins_left[j]] = dir;
            }
            else
            {
                debug(dir, endl);
                if (coins[coins_left[j]] != dir ||
                    direction == "even")
                    coins[coins_left[j]] = 'e';
            }
            debug(coins_left[j], TAB); debug(coins[coins_left[j]], endl);
        }

        REP(j, coins_right.length())
        {
            if (coins.find(coins_right[j]) == coins.end())
            {
                coins[coins_right[j]] = direction[0];
            }
            else
            {
                if (coins[coins_right[j]] != direction[0] ||
                    direction == "even")
                    coins[coins_right[j]] = 'e';
            }
            debug(coins_right[j], TAB); debug(coins[coins_right[j]], endl);
        }


        getInput();
    } while (i++ != 2);

    dbg(dump());
    
    for (map<char, char>::iterator it = coins.begin(); it != coins.end(); it++)
    {
        if (it->second != 'e')
        {
            a = it->first;
            b = it->second;
            break;
        }
    }
    
    
    printf("%c is the counterfeit coin and it is %s.\n", a, (b == 'u') ? "light" : "heavy");
}

int main()
{
    int nc;
    scanf("%d\n", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
