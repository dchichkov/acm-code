#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

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
vp segments;
int M;

struct cmp
{
    bool operator()(const point& a, const point& b)
    {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }
};

/*global variables*/

void dump()
{
    //dump data
    debug(M, endl);
    REP(i, segments.size())
    {
        debug(segments[i].first, TAB);
        debug(segments[i].second, endl);
    }
}

bool getInput()
{
    //get input
    point a;
    scanf("%d", &M);

    do
    {
        scanf("%d %d", &a.first, &a.second);
        if (a.second > 0 && a.first < M) //useless segment, coverage is from 0 to M, therefore this says covers is <= 0
            segments.push_back(a);    
    }
    while (a.first != 0 || a.second != 0);
    
    return true;
}

void process()
{
    //process input
    sort(segments.begin(), segments.end(), cmp());
    dbg(dump());
    vp ans;
    int N = 0, max_cov = 0;
    vp::iterator max_it;
    while (N < M && !segments.empty())
    {
        //get max coverage
        max_it = segments.end();
        max_cov = 0;
        for (vp::iterator it = segments.begin(); it != segments.end(); ++it)
        {
            if (it->first > N || it->second < N)
            {
                debug(it->first, TAB); debug(N, endl);
                continue; //begins in a useless place
            }
            if (it->second - it->first >= max_cov)
            {
                max_cov = it->second - it->first;
                max_it = it;
                debug(max_cov, endl);
            }   
        }
        if (max_it == segments.end()) //no more coverable segments
            break;
        else
        {
            debug(max_it->first, TAB); debug(max_it->second, endl);
            ans.push_back(*max_it);
            N = max_it->second;
            segments.erase(max_it);
        }
    }

    if (N < M)
        ans.clear();
    
    printf("%d\n", (int)ans.size());
    REP(i, ans.size())
    {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
}

int main()
{
    int nc;
    scanf("%d", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();

        //if (nc != 0)
        printf("\n");
        
        /*CLEAR GLOBAL VARIABLES!*/
        segments.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
