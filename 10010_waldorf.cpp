#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

#define DEBUG
#undef DEBUG //uncomment this line to pull out print statements
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

//directions aren't actually correct, since the directions are backwards, and x is y and y is x
//but it works.
enum direction { WEST = 0, SOUTHWEST, SOUTH, SOUTHEAST, EAST, NORTHEAST, NORTH, NORTHWEST };
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
    char alpha;
    FOR(i, 1, height)
        FOR(j, 1, width)
        {
            scanf("%c%*[ \n]", &alpha);
            grid[i][j] = tolower(alpha);
        }

    scanf("%d", &num_words);
    REP(i, num_words)
    {
        scanf("%s\n", wordlist[i]);
    }
    
    REP(i, num_words)
        REP(j, strlen(wordlist[i]))
        wordlist[i][j] = tolower(wordlist[i][j]);
    
    return true;
}

bool check_match(int x, int y, direction pos, char* word, int char_pos)
{
    debug(word, TAB); debug(word[char_pos], TAB); debug(grid[x][y], endl);
    if (word[char_pos] == grid[x][y] && char_pos == strlen(word)-1)
        return true;
    else if (word[char_pos] != grid[x][y]) return false;

    return check_match(x+rangex[pos], y+rangey[pos], pos, word, char_pos+1);
}

void process()
{
    //process input
    bool is_match = false;
    int j, k;
    REP(i, num_words)
    {
        for (j = 1; j < height; ++j)
        {
            for (k = 1; k < width; ++k)
            {
                if (grid[j][k] == wordlist[i][0])
                {
                    debug(j, TAB); debug(k, endl);
                    if (check_match(j+rangex[EAST], k+rangey[EAST], EAST, wordlist[i], 1) || 
                        check_match(j+rangex[NORTHEAST], k+rangey[NORTHEAST], NORTHEAST, wordlist[i], 1) || 
                        check_match(j+rangex[NORTH], k+rangey[NORTH], NORTH, wordlist[i], 1) || 
                        check_match(j+rangex[NORTHWEST], k+rangey[NORTHWEST], NORTHWEST, wordlist[i], 1) || 
                        check_match(j+rangex[WEST], k+rangey[WEST], WEST, wordlist[i], 1) || 
                        check_match(j+rangex[SOUTHWEST], k+rangey[SOUTHWEST], SOUTHWEST, wordlist[i], 1) || 
                        check_match(j+rangex[SOUTH], k+rangey[SOUTH], SOUTH, wordlist[i], 1) || 
                        check_match(j+rangex[SOUTHEAST], k+rangey[SOUTHEAST], SOUTHEAST, wordlist[i], 1))
                    {
                        is_match = true;
                        break;
                    }
                }
            }
            if (is_match)
                break;
        }
        //output coords
        if (is_match)
            printf("%d %d\n", j, k);
        
        is_match = false;
    }
}

int main()
{
    int nc;
    scanf("%d\n", &nc);
    while (nc-- > 0)
    {
        getInput();
        //dump();
        process();

        /*output*/
        if (nc != 0)
            cout << endl;

        /*output*/
    }

    return 0;
}
