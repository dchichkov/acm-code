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
struct rect
{
    double top, left, bottom, right;
};
vector<rect> tangles;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    rect a;
    char opt = ' ';
    while (opt != '*')
    {
        scanf("%c ", &opt);
        switch (opt)
        {
        case 'r':
            scanf("%lf %lf %lf %lf ", &a.left, &a.top, &a.right, &a.bottom);
            tangles.push_back(a);
            break;
        }
    }
    return true;
}

void process()
{
    //process input
    pair<double, double> pt;
    int i = 1, j = 1, c = 0;
    scanf("%lf %lf ", &pt.first, &pt.second);
    while ((10*pt.first) != 99999 && (10*pt.second) != 99999)
    {
        j = 1;
        c = 0;
        for (vector<rect>::iterator it = tangles.begin(); it != tangles.end(); ++it, ++j)
        {
            if ((pt.first > it->left && pt.first < it->right) &&
                (pt.second < it->top && pt.second > it->bottom))
            {
                printf("Point %d is contained in figure %d\n", i, j);
                ++c;
            }
        }
        if (c == 0)
            printf("Point %d is not contained in any figure\n", i);
        ++i;
        scanf("%lf %lf ", &pt.first, &pt.second);
    }
}

int main()
{
    //while (getInput())
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        tangles.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
