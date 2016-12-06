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
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int walls, cameras;
int mn; //magical starting point
vp cover;
/*global variables*/

struct sortp
{
    bool operator()(const point& a, const point& b)
    {
        if (a.first != b.first)
            return a.first < b.first;
        else
            return a.second > b.second;
    }
};

void dump()
{
    //dump data
    REP(i, cameras)
    {
        debug(cover[i].first, TAB); debug(cover[i].second, endl);
    }
    puts("");
}

bool can_cover()
{
    bool* hmm = new bool[walls];
    bool check = true;
    REP(i, cameras)
    {
        if (cover[i].first > cover[i].second)
        {
            for (int j = cover[i].first; j < walls; ++j)
                hmm[j] = 1;
            for (int j = 0; j < cover[i].second; ++j)
                hmm[j] = 1;
        }
        else
        {
            for (int j = cover[i].first; j < cover[i].second; ++j)
                hmm[j] = 1;
        }
    }

    REP(i, walls)
    {
        if (hmm[i] == 0) check = false;
    }
    
    delete hmm;
    return check;
}

bool getInput()
{
    //get input
    scanf("%d %d ", &walls, &cameras);
    mn = walls / 3;
    point a;
    REP(i, cameras)
    {
        scanf("%d %d ", &a.first, &a.second);
        cover.push_back(a);
    }
    return true;
}

void process()
{
    //process input
    sort(cover.begin(), cover.end(), sortp());
    dump();
    debug(can_cover(), endl);

    if (!can_cover())
    {
        printf("impossible");
        return;
    }
    
    vp starting_points;
    int positions[cameras];
    //find starting points
    int k_ = 0;
    REP(i, cameras)
    {
        if (cover[i].first > cover[i].second)
        {
            if (mn > cover[i].first && mn < cover[i].second+walls)
            {
                starting_points.push_back(cover[i]);
                positions[k_++] = i;
            }
        }
        else
        {
            if (mn > cover[i].first && mn < cover[i].second)
            {
                starting_points.push_back(cover[i]);
                positions[k_++] = i;
            }
        }
    }

    //go from starting point grabbing the largest
    int mn = 1000001, cnt;
    int edge;
    REP(i, (int)starting_points.size())
    {
        cnt = 0;
        debug(positions[i]+1, TAB);
        debug(starting_points[i].first, TAB);
        debug(starting_points[i].second, endl);
        edge = starting_points[i].second;
        int a = 0;
        for (int j = positions[i]+1; j != positions[i]; j = (j + 1)%cameras)
        {
            if (edge > cover[j].first)
                continue;
            debug(cover[j].first, TAB); debug(edge, endl);
            edge = cover[j].second;
            cnt++;
        }
        mn = min(mn, cnt);
        debug(cnt, TAB); debug(mn, endl);
    }
}

int main()
{
//    while ()
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
