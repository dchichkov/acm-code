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
char graph[12][12];
char area[12][12];
const char bomb = '*';
int n;

int rangex[] = {1, 1, 0, -1, -1, -1, 0, 1};
int rangey[] = {0, -1, -1, -1, 0, 1, 1, 1};
/*global variables*/

void dump()
{
    //dump data
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            printf("%c", graph[i][j]);
        }
        cout << endl;
    }
}

bool getInput()
{
    //get input
    CL2d(graph, 0, n, n); //zero out the map
    CL2d(area, 0, n, n); //zero out the map
    scanf("%d ", &n);
    //debug(width, TAB); debug(height, endl);
    
    n += 1;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            scanf("%c%*[ \n]", &graph[i][j]);
            if (graph[i][j] == '.')
                graph[i][j] = 0;
        }
    }

    for (int i = 1; i < n; ++i)
        for (int j = 1; j < n; ++j)
            scanf("%c%*[ \n]", &area[i][j]);
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

void show_mines()
{
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            if (graph[i][j] == bomb)
            {
                area[i][j] = 'x';
                graph[i][j] = bomb-'0';
            }
        }
    }
}

int main()
{
    int num_cases;
    scanf("%d\n", &num_cases);
    bool show_bombs = false;
    while (num_cases-- > 0)
    {
        getInput();
        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (graph[i][j] == bomb)
                    addonetoneighbors(i, j);
            }
        }

        /*output*/
        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (area[i][j] == 'x')
                {
                    if (graph[i][j] == bomb)
                    {
                        show_bombs = true;
                        show_mines();
                    }
                }
            }

        }
        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (area[i][j] == 'x')
                {
                    printf("%c", graph[i][j]+'0');
                }
                else
                    printf(".");
            }
            if (i+1 != n)
                cout << endl;
        }

        
        show_bombs = false;
        /*output*/
        if (num_cases != 0)
            cout << endl << endl;
    }
}
