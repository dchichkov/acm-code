/* Class:   CSC 2700 Programming Competitions
 * Prof:    Isaac Traxler
 * Name:    Matthew Gavin
 * Problem: 638 - Rectangles
 *
 * Note: Only 3 loops are required... I don't know why I was trying to recursively backtrack ;)
 *       This is a very simple problem!
 */ 

#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
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

typedef vector<int> vi; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/

struct point {
    char ltr;
    int x;
    int y;
};

int num_pt;
point pts[26];
char rects[500][5];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d ", &num_pt);
    if (num_pt == 0) return false;
    //debug(num_pt, endl);

    REP(i, num_pt)
    {
        scanf("%c %d %d ", &pts[i].ltr, &pts[i].x, &pts[i].y);
        //debug(p.ltr, TAB); debug(p.x, TAB); debug(p.y, endl);
    }
    
    return true;
}

void process()
{
    //process input
    int cnt = 0;
    REP(i, num_pt)
    {

        FOR(j, 0, num_pt)
        {
            if (j == i) continue;
            //right
            if (pts[j].x > pts[i].x && pts[j].y == pts[i].y)
            {
                //found right
                debug(r, endl);
                FOR(k, 0, num_pt)
                {
                    if (k == i || k == j) continue;
                    //go down
                    if (pts[k].y < pts[j].y && pts[k].x == pts[j].x)
                    {
                        //found down
                        debug(r, endl);
                        FOR(l, 0, num_pt)
                        {
                            if (l == i || l == j || l == k) continue;
                            //go left
                            if ((pts[l].x < pts[k].x && pts[l].y == pts[k].y) &&
                                (pts[l].x == pts[i].x && pts[i].y > pts[l].y))
                            {
                                debug(r, endl);
                                //found left and compared with the starting point
                                rects[cnt][0] = pts[i].ltr;
                                rects[cnt][1] = pts[j].ltr;
                                rects[cnt][2] = pts[k].ltr;
                                rects[cnt][3] = pts[l].ltr;
                                rects[cnt][4] = 0;
                                cnt++;
                            }
                        }
                    }
                }
            }
        }
    }

    //sort(rects, rects+cnt);
    if (cnt == 0)
        fputs(" No rectangles", stdout);
    else
    {
        puts("");
        REP(i, cnt)
        {
            if (i % 10 == 0 && i != 0)
                puts("");
            fputs(" ", stdout);
            fputs(rects[i], stdout);
        }
    }
    puts("");
}

int main()
{
    int nc = 0;
    while (getInput())
    {
        printf("Point set %d:", ++nc);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        CL2d(rects, 0, 500, 5);
        CL(pts, 0);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
