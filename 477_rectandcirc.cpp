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
struct shape
{
    char type;
    double top, left, bottom, right; //rectangle
    double centerx, centery, radius; //circle
};
vector<shape> shapes;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    shape a;
    char opt = ' ';
    while (opt != '*')
    {
        scanf("%c ", &opt);
        switch (opt)
        {
        case 'r':
            a.type = 'r';
            scanf("%lf %lf %lf %lf ", &a.left, &a.top, &a.right, &a.bottom);
            shapes.push_back(a);
            break;
        case 'c':
            a.type = 'c';
            scanf("%lf %lf %lf ", &a.centerx, &a.centery, &a.radius);
            shapes.push_back(a);
            break;     
        }
    }
    return true;
}

void process()
{
    //process input
    pair<double, double> pt;
    int i = 1, coun = 0;
    shape a;
    scanf("%lf %lf ", &pt.first, &pt.second);
    while ((10*pt.first) != 99999 && (10*pt.second) != 99999)
    {
        coun = 0;
        //go through shapes
        for (int j = 0; j < shapes.size(); ++j)
        {
            a = shapes[j];
            switch(a.type)
            {
            case 'r':
            {
                if ((pt.first > a.left && pt.first < a.right) &&
                    (pt.second < a.top && pt.second > a.bottom))
                {
                    printf("Point %d is contained in figure %d\n", i, j+1);
                    ++coun;
                }
            }
                break;
            case 'c':
                /*if point is under radial distance to center
                 * (x2-x1)^2 + (y2-y1)^2 = distance^2 from pt a (x2, y2) to pt b (x1, y1);
                 * sqrt(a*a + b*b) = c == distance formula
                 */
                double dist = ((abs(pt.first - a.centerx) * abs(pt.first - a.centerx))+
                               (abs(pt.second - a.centery) * abs(pt.second - a.centery)));
                if (dist < (a.radius*a.radius))
                {
                    printf("Point %d is contained in figure %d\n", i, j+1);
                    ++coun;
                }
                break;
            }
        }      
        //if none
        if (coun == 0)
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
        shapes.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
