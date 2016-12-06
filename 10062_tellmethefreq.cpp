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

struct sort_func
{
    bool operator()(const pair<int,int>& a, const pair<int,int>& b)
    {
        if (a.second == b.second)
            return (a.first > b.first);
        else
            return (a.second < b.second);
    }
} sort_fun;

/*global variables*/
char line[1050];
map<int, int> freqs;
vp sorts;

bool first_time; //lame
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (fgets(line, 1050, stdin) == NULL) return false;
    return true;
}

void process()
{
    if (first_time)
        printf("\n");
    else first_time = true;
    
    //process input
    REP(i, strlen(line))
    {
        if ((int)line[i] > 31 && (int)line[i] < 128)
            freqs[(int)line[i]]++;
    }

    for (map<int, int>::iterator it = freqs.begin(); it != freqs.end(); ++it)
    {
        point x;
        x.first = it->first;
        x.second = it->second;
        sorts.push_back(x);
    }
    sort(sorts.begin(), sorts.end(), sort_fun);

    for (vp::iterator it = sorts.begin(); it != sorts.end(); ++it)
    {
        printf("%d %d\n", it->first, it->second);
    }
}

int main()
{
    first_time = false;
    bool moreToDo;
    while (moreToDo = getInput())
    {

        process();

        /*output*/

        /*output*/
        CL(line, 0);
        freqs.clear();
        sorts.clear();
    }

    return 0;
}
