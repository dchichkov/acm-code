#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
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
const int mxlen = 4+2;
char matrix[mxlen][mxlen];

int movx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int movy[] = {0, 1, 1, 1, 0, -1, -1, -1};

vector<string> words;

int points[] = {0, 0, 0, 1, 1, 2, 3, 5, 11};

//directions aren't actually correct, since the directions are backwards, and x is y and y is x
//but it works.
enum direction { WEST = 0, SOUTHWEST, SOUTH, SOUTHEAST, EAST, NORTHEAST, NORTH, NORTHWEST };
/*/global variables*/

void dump()
{
    //dump data

    dbg(
    FOR(i, 1, 5)
    {
        printf("%s\n", &matrix[i][1]);
    }
    puts("");
        );
}

bool getInput()
{
    //get input

    FOR(i, 1, 5)
    {
        scanf("%s ", &matrix[i][1]);
    }

    dbg(
    FOR(i, 1, 5)
    {
        printf("%s\n", &matrix[i][1]);
    }
    puts("");
        );
    char word[18];
    int n;
    scanf("%d ", &n);
    REP(i, n)
    {   
        scanf("%s ", word);
        words.push_back(word);
    }
    
    return true;
}

bool check_match(int x, int y, direction pos, string word, int char_pos)
{
    debug(word, TAB); debug(word[char_pos], TAB); debug(matrix[x][y], endl);
    if (word[char_pos] == matrix[x][y] && char_pos == word.length()-1)
    {

        return true;
    }
    else if (word[char_pos] != matrix[x][y]) return false;

    return (check_match(x+movx[EAST], y+movy[EAST], EAST, word, char_pos+1) || 
                        check_match(x+movx[NORTHEAST], y+movy[NORTHEAST], NORTHEAST, word, char_pos+1) || 
                        check_match(x+movx[NORTH], y+movy[NORTH], NORTH, word, char_pos+1) || 
                        check_match(x+movx[NORTHWEST], y+movy[NORTHWEST], NORTHWEST, word, char_pos+1) || 
                        check_match(x+movx[WEST], y+movy[WEST], WEST, word, char_pos+1) || 
                        check_match(x+movx[SOUTHWEST], y+movy[SOUTHWEST], SOUTHWEST, word, char_pos+1) || 
                        check_match(x+movx[SOUTH], y+movy[SOUTH], SOUTH, word, char_pos+1) || 
                        check_match(x+movx[SOUTHEAST], y+movy[SOUTHEAST], SOUTHEAST, word, char_pos+1));
}

void process()
{
    //process input
    dbg(
    dump();
        );
    bool is_match = false;
    int j, k, total = 0;
    REP(i, (int)words.size())
    {
        for (j = 1; j < 6; ++j)
        {
            for (k = 1; k < 6; ++k)
            {
                if (matrix[j][k] == words[i][0])
                {
                    debug(j, TAB); debug(k, endl);
                    if (check_match(j+movx[EAST], k+movy[EAST], EAST, words[i], 1) || 
                        check_match(j+movx[NORTHEAST], k+movy[NORTHEAST], NORTHEAST, words[i], 1) || 
                        check_match(j+movx[NORTH], k+movy[NORTH], NORTH, words[i], 1) || 
                        check_match(j+movx[NORTHWEST], k+movy[NORTHWEST], NORTHWEST, words[i], 1) || 
                        check_match(j+movx[WEST], k+movy[WEST], WEST, words[i], 1) || 
                        check_match(j+movx[SOUTHWEST], k+movy[SOUTHWEST], SOUTHWEST, words[i], 1) || 
                        check_match(j+movx[SOUTH], k+movy[SOUTH], SOUTH, words[i], 1) || 
                        check_match(j+movx[SOUTHEAST], k+movy[SOUTHEAST], SOUTHEAST, words[i], 1))
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
            total += points[min(8, (int)words[i].length())];
        is_match = false;
    }

    printf("%d\n", total);
}

int main()
{
    int nc, count = 0;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        CL2d(matrix, 0, mxlen, mxlen);
        getInput();
        printf("Score for Boggle game #%d: ", ++count);
        
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        words.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
