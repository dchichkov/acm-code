#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <bitset>

using namespace std;

#define DEBUG
#undef DEBUG //uncomment this line to pull out print statements
#ifdef DEBUG
#define TAB '\t'
#define debug(a, end) cout << #a << ": " << a << end
#else
#define debug(a, end)
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
bitset<50> sample;
int a[50000];
int num;
/*global variables*/

void dump()
{
    //dump data
}

bool ispalindrome(string x, size_t n)
{
    string s = x.substr(x.length()-n);
    debug(s, endl);
    for (size_t i = 0; i < s.length()/2; ++i)
    {
        debug(s[i], TAB); debug(s[s.length()-i-1], endl);
        if (s[i] != s[s.length()-i-1])
            return false;
    }

    return true;
}

void precompute()
{
    a[0] = 1;
    for (int i = 1, num = i+1; i < 50000; ++num)
    {
        sample &= ~sample; //clear
        sample |= num;
        debug(sample.to_string(), endl);
        /*if (ispalindrome(sample.to_string(), log2(num)+1))
          {*/
        debug((sample ^ ((sample >> log2(num)) << log2(num))).to_string(), endl);
        if ((sample ^ ((sample >> log2(num)) << log2(num))).to_ulong() ==
            (sample >> log2(num)).to_ulong())
        {
            cout << num << ": " << i << endl;
            a[i++] = num;
        }
    }
}

bool getInput()
{
    //get input
    if (scanf("%d", &num) == EOF) return false;
    return true;
}

void process()
{
    //process input
    printf("%d\n", a[num-1]);
}

int main()
{
    precompute();
    debug(ispalindrome("abcba", 5), endl);
    bool moreToDo;
    while (moreToDo = getInput())
    {

        process();

        /*output*/


        /*output*/
    }

    return 0;
}
