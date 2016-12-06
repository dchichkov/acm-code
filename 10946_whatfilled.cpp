#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>

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
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
char cmap[55][55];
int sizex, sizey;
map<int, string> counts;

/*int movex[] = {1, 1, 0, -1, -1, -1, 0, 1};
int movey[] = {0, 1, 1, 1, 0, -1, -1, -1};*/
int movex[] = {1, 0, -1, 0};
int movey[] = {0, 1, 0, -1};
/*global variables*/

void dump()
{
    //dump data
    FOR(i, 1, sizex+1)
    {
        FOR(j, 1, sizey+1)
        {
            printf("%c", cmap[i][j]);
        }
        printf("\n");
    }
}

bool getInput()
{
    //get input
    scanf("%d %d ", &sizex, &sizey);
    if (sizex == 0 && sizey == 0)
        return false;

    FOR(i, 1, sizex+1)
    {
        FOR(j, 1, sizey+1)
        {
            scanf("%c ", &cmap[i][j]);
        }
    }
    
    return true;
}

void floodfill(int x, int y, int& num, char lookfor)
{
    for (int i = 0; i < 4; ++i)
    {
        if (cmap[x+movex[i]][y+movey[i]] == lookfor)
        {
            cmap[x+movex[i]][y+movey[i]] = 0;
            num += 1;
            floodfill(x+movex[i], y+movey[i], num, lookfor);
        }
    }

}

void process()
{
    //process input
    int num = 0;
    char curchar;
    debug(sizex, TAB); debug(sizey, endl);
    dbg(dump());

    FOR(i, 1, sizex+1)
    {
        FOR(j, 1, sizey+1)
        {
            num = 0;
            if (cmap[i][j] != 0 &&
                cmap[i][j] != '.')
            {
                curchar = cmap[i][j];
                cmap[i][j] = 0;
                num += 1;
                floodfill(i, j, num, curchar);
            }
            /*dbg(dump());
            dbg(cout << endl);
            debug(num, TAB); debug(curchar, endl);*/
            if (num != 0)
            {
                if (counts.find(num) != counts.end())
                    counts[num] += curchar;
                else
                    counts[num] = curchar;
            }
        }
    }

    for (map<int,string>::reverse_iterator it = counts.rbegin();
         it != counts.rend();
         ++it)
    {
        sort((it->second).begin(), (it->second).end());
        debug(it->first, TAB); debug(it->second, endl);
        for (std::size_t c = 0; c < (it->second).length(); ++c)
        {
            printf("%c %d\n", (it->second).at(c), it->first);
        }
    }
    //printf("\n");
}

int main()
{
    CL2d(cmap, 0, 55, 55);
    int pnum = 0;
    while (getInput())
    {

        printf("Problem %d:\n", ++pnum);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        CL2d(cmap, 0, 55, 55);        
        counts.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
