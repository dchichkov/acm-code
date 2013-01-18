#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

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
int round_num;
string answer, guess;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d ", &round_num);
    if (round_num == -1) return false;

    getline(cin, answer);
    getline(cin, guess);
    
    return true;
}

void process()
{
    //process input
    printf("Round %d\n", round_num);

    int try_count = 0;
    bool gg = false;
    //remove duplicates
    for (int i = 0; i < guess.length(); ++i)
    {
        for (int j = i+1; j < guess.length(); ++j)
        {
            if (guess[i] == guess[j]) guess.erase(j--, 1);
        }
    }
    debug(guess, endl);
    debug(answer, endl);
    for (int i = 0; i < guess.length(); ++i)
    {
        gg = false;
        for (int j = 0; j < answer.length(); ++j)
        {
            debug(guess[i], TAB); debug(answer[j], TAB);
            if (guess[i] == answer[j])
            {
                gg = true;
                answer.erase(j--, 1);
                debug(answer, endl);
            }
        }
        if (answer.length() == 0) break;
        if (!gg) try_count++;
        if (try_count >= 7) break;
    }    
    debug(answer, endl);
    debug(answer.length(), endl);

    printf("You %s.\n", (try_count >= 7) ? "lose" : (answer.length() > 0) ? "chickened out" : "win");
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
