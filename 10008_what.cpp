#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

#define DEBUG
//#undef DEBUG //uncomment this line to pull out print statements
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
struct sortmap
{
    bool operator()(const pair<char, int>& a, const pair<char, int>& b)
    {
        return a.second > b.second;
    }
};

map<char, int> lc;
string line;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    getline(cin, line);
    return true;
}

void process()
{
    //process input
    REP(i, line.length())
    {
        if (isalpha(line[i]))
            lc[toupper(line[i])] += 1;
    }
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

    vector<pair<char, int> > sup;
    for (map<char, int>::iterator it = lc.begin(); it != lc.end(); ++it)
        sup.push_back(*it);
    sort(sup.begin(), sup.end(), sortmap());
    
    REP(i, sup.size())
    {
        cout << sup[i].first << " " << sup[i].second << endl;
    }

    return 0;
}
