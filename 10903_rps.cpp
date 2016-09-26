#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

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
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,(int)n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
vector<vi> players;
int n, k;
bool first;
#define EPS 1e-9
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d ", &n);
    if (n == 0) return false;
    scanf("%d ", &k);
    return true;
}

int score(const string& p1, const string& p2)
{
    if (p1 == "rock")
    {
        if (p2 == "rock")
            return 0;
        if (p2 == "paper")
            return -1;
        if (p2 == "scissors")
            return 1;
    }
    if (p1 == "paper")
    {
        if (p2 == "rock")
            return 1;
        if (p2 == "paper")
            return 0;
        if (p2 == "scissors")
            return -1;
    }
    if (p1 == "scissors")
    {
        if (p2 == "rock")
            return -1;
        if (p2 == "paper")
            return 1;
        if (p2 == "scissors")
            return 0;
    }
    return -2;
}
        

void process()
{
    //process input
    players.resize(n+1);
    int a, b;
    char am[20], bm[20];
    k = ((k*n*(n-1))/2);
    REP(i, k)
    {
        scanf("%d %s %d %s ", &a, am, &b, bm);
        players[a].push_back(score(am, bm));
        players[b].push_back(score(bm, am));
    }

    double w, l;
    for (int i = 1; i < players.size(); ++i)
    {
        w = l = 0;
        for (vi::iterator it = players[i].begin(); it != players[i].end(); ++it)
        {
            if (*it == 1) w++;
            else if (*it == -1) l++;
        }
        if (int(w+l) == 0) printf("-");
        else printf("%0.3lf", w / (w+l));
        puts("");
    }
}

int main()
{
    while (getInput())
    {
        if (first) puts("");
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        players.clear();
        /*CLEAR GLOBAL VARIABLES!*/
        first = true;
    }

    return 0;
}
