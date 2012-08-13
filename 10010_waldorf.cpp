#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

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
int height, width;
char grid[52][52];
int rangex[] = {1, 1, 0, -1, -1, -1, 0, 1};
int rangey[] = {0, 1, 1, 1, 0, -1, -1, -1};
char word[100];
char wordlist[22][100];
int num_words;

enum { EAST = 0, NORTHEAST, NORTH, NORTHWEST, WEST, SOUTHWEST, SOUTH, SOUTHEAST };
/*global variables*/

void dump()
{
    //dump data
    FOR(i, 1, height)
    {
        FOR(j, 1, width)
            printf("%c", grid[i][j]);
        printf("\n");
    }

    REP(i, num_words)
    {
        printf("%s\n", wordlist[i]);
    }
}

bool getInput()
{
    CL2d(grid, 0, height, width);
    CL2d(wordlist, 0, 22, 100);
    //get input
    scanf("%d %d\n", &height, &width);
    debug(height, TAB); debug(width, endl);
    height += 1;
    width += 1;
    FOR(i, 1, height)
    {
        FOR(j, 1, width)
        {
            scanf("%c%*[ \n]", &grid[i][j]);
        }
    }
    scanf("%d", &num_words);
    REP(i, num_words)
    {
        scanf("%s\n", wordlist[i]);
    }
    return true;
}

void process()
{
    //process input
    
}

int main()
{
    int nc;
    scanf("%d\n", &nc);
    while (nc-- > 0)
    {
        getInput();
        dump();
        process();

        /*output*/


        /*output*/
    }

    return 0;
}
