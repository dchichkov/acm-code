#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cctype>
#include <set>

using namespace std;

//#define DEBUG
//#undef DEBUG //uncomment this line to pull out print statements
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
struct compare
{
    bool operator() (const string& a, const string& b)
    {
        bool t = false;
        for (size_t i = 0; i < a.length() && i < b.length(); ++i)
            if (toupper(a[i]) < toupper(b[i]))
                return true;
            else if (toupper(a[i]) > toupper(b[i]))
                return false;
            else if (toupper(a[i]) == toupper(b[i]))
                if ( a[i] < b[i] )
                    return true;
        /*t = a[i] < b[i] ? true : false;

          return t;*/

    }
};

struct comp
{
    bool operator() (const char& a, const char& b)
    {
        debug(a, TAB); debug(b, TAB); debug((isupper(a) ? a < b : b > a), endl);
        return (isupper(a) ? a < b : b > a);
    }
};
string word;
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
    set<string, compare> words;
    //SORT(word);
    do
    {
        words.insert(word);
        debug(word, endl);
    }
    while (next_permutation(word.begin(), word.end(), comp()));

    //quick hack.
    do
    {
        words.insert(word);
        debug(word, endl);
    }
    while (next_permutation(word.begin(), word.end()));
    

    //sort(words.begin(), words.end(), compare());
    //SORT(words);
    for (set<string>::iterator it = words.begin(); it != words.end(); ++it)
        printf("%s\n", it->c_str());

    debug(words.size(), endl);
}

int main()
{
    int nc;
    scanf("%d", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
