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
string word;
vector<vi> words;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    cin >> word;
    return true;
}
void to_int(vector<int>& wordx)
{
    REP(i, word.length())
    {
        wordx.push_back((int)word[i]);
    }
}

string to_str(const vector<int> wordx)
{
    string s;
    REP(i, wordx.size())
    {
        s += (char)wordx[i];
    }
    return s;
}

    
void process()
{
    //process input
    vector<int> sigh;
    to_int(sigh);
    do
    {
        words.push_back(sigh);
    } while (next_permutation(sigh.begin(), sigh.end()));

    REP(i, words.size())
    {
        cout << to_str(words[i]) << endl;
    }
    
}

int main()
{
    int nc = 0;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        words.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
