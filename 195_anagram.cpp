#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
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
vector<string> words;

struct cmp
{
    bool operator()(const char& a, const char& b)
    {
        if (toupper(a) == toupper(b))
            return a < b;
        else
            return toupper(a) < toupper(b);
    }
};

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
    
void process()
{
    //process input
    sort(word.begin(), word.end(), cmp());
    do
    {
        words.push_back(word);
    } while (next_permutation(word.begin(), word.end(), cmp()));

    for (vector<string>::iterator it = words.begin(); it != words.end(); ++it)
        cout << *it << endl;
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
