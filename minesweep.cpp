#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>

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

/*global variables*/
char graph[102][102];
const char bomb = '*';
int height, width;

int rangex[] = {1, 1, 0, -1, -1, -1, 0, 1};
int rangey[] = {0, -1, -1, -1, 0, 1, 1, 1};
/*global variables*/

void dump()
{
    //dump data
    for (int i = 1; i < height; ++i)
    {
        for (int j = 1; j < width; ++j)
        {
            printf("%c", graph[i][j]);
        }
        cout << endl;
    }
}

bool getInput()
{
    //get input
    CL2d(graph, 0, height, width); //zero out the map
    scanf("%d %d%*[ \n]", &height, &width);
    //debug(width, TAB); debug(height, endl);
    if (width == 0 and height == 0)
        return false;
    
    width += 1;
    height += 1;
    for (int i = 1; i < height; ++i)
    {
        for (int j = 1; j < width; ++j)
        {
            scanf("%c%*[ \n]", &graph[i][j]);
            if (graph[i][j] == '.')
                graph[i][j] = 0;
        }
    }
    //dump();

    return true;
}

void addonetoneighbors(int x, int y)
{
    //process input
    for (int i = 0; i < 8; ++i)
    {
        if (graph[x+rangex[i]][y+rangey[i]] != bomb)
            graph[x+rangex[i]][y+rangey[i]]++;
    }
}

int main()
{
    bool moreToDo;
    int counter = 1;
    moreToDo = getInput();
    while (moreToDo)
    {

        for (int i = 1; i < height; ++i)
        {
            for (int j = 1; j < width; ++j)
            {
                if (graph[i][j] == bomb)
                    addonetoneighbors(i, j);
            }
        }

        /*output*/
        printf("Field #%d:\n", counter++);
        for (int i = 1; i < height; ++i)
        {
            for (int j = 1; j < width; ++j)
            {
                if (graph[i][j] != bomb)
                    printf("%d", graph[i][j]);
                else
                    printf("%c", graph[i][j]);
            }
            cout << endl;
        }
        /*output*/
        moreToDo = getInput();
        if (moreToDo)
            cout << endl;
    }
}
