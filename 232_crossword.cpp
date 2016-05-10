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
int l, w;
char grid[12][12];
char grid2[12][12];

bool nfirst = false;

struct words
{
    short da; //1 for across, 2 for down
    string word;
    int num_on_board;
};
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d ", &l);
    if (l == 0) return false;
    scanf("%d ", &w);

    FOR(i, 1, l+1)
    {
        FOR(j, 1, w+1)
        {
            scanf("%c", &grid[i][j]);
            grid2[i][j] = grid[i][j];
            
        }
        scanf(" ");
    }
    return true;
}

void process()
{
    int num;
    //process input
    vector<words> puzzle;
    words base;
    //do accross with grid 1
    bool fw;
    num = 0;
    FOR(i, 1, l+1)
    {
        for (int j = 1; j < w+1; ++j)
        {
            string worda; //word across
            string wordd; //word down
            fw = false;
            if (grid[i][j] != '*' && grid[i][j] != 0) //found word
            {
                fw = true;
                int k = j+1;
                worda += grid[i][j];
                grid[i][j] = 0;
                while (k < w+1)
                {
                    if (grid[i][k] != '*' && grid[i][k] != 0) //continue finding word
                    {
                        worda += grid[i][k];
                        grid[i][k] = 0;
                    }
                    else break;
                    ++k;
                }
                if (fw) num++;
                base.num_on_board = num;
                base.da = 1; //across
                base.word = worda;
                puzzle.push_back(base);
            }
            if (grid2[i][j] != '*' && grid2[i][j] != 0) //found word - down
            {
                int k = i+1;
                wordd += grid2[i][j];
                grid2[i][j] = 0;
                while (k < l+1)
                {
                    if (grid2[k][j] != '*' && grid2[k][j] != 0) //continue finding down
                    {
                        wordd += grid2[k][j];
                        grid2[k][j] = 0;
                    }
                    else break;
                    ++k;
                }
                if (!fw) num++;
                base.num_on_board = num;
                base.da = 2; // down
                base.word = wordd;
                puzzle.push_back(base);
            }   
        }
    }

    printf("Across\n");
    for (int i = 0; i < puzzle.size(); ++i)
    {
        if (puzzle[i].da == 1)
        {
            printf("%3d.%s\n", puzzle[i].num_on_board, puzzle[i].word.c_str());
        }
    }
    printf("Down\n");
    for (int i = 0; i < puzzle.size(); ++i)
    {
        if (puzzle[i].da == 2)
        {
            printf("%3d.%s\n", puzzle[i].num_on_board, puzzle[i].word.c_str());
        }
    }
    //puts("");
}

int main()
{
    int puzzlenum = 1;
    while (getInput())
    {
        if (nfirst) puts("");
        else nfirst = !nfirst;            
        printf("puzzle #%d:\n", puzzlenum++);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        CL2d(grid, 0, 12, 12);
        CL2d(grid2, 0, 12, 12);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
