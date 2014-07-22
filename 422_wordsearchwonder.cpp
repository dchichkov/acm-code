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
const int mxlen = 100;
char matrix[mxlen+2][mxlen+2];
int len;

int movx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int movy[] = {0, 1, 1, 1, 0, -1, -1, -1};

vector<string> words;

//directions aren't actually correct, since the directions are backwards, and x is y and y is x
//but it works.
enum direction { WEST = 0, SOUTHWEST, SOUTH, SOUTHEAST, EAST, NORTHEAST, NORTH, NORTHWEST };
/*global variables*/

void dump()
{
    //dump data

    dbg(
    FOR(i, 1, len+1)
    {
        printf("%s\n", &matrix[i][1]);
    }
    puts("");
        );
}

bool getInput()
{
    //get input

    scanf("%d ", &len);
    FOR(i, 1, len+1)
    {
        scanf("%s ", &matrix[i][1]);
    }

    dbg(
    FOR(i, 1, len+1)
    {
        printf("%s\n", &matrix[i][1]);
    }
    puts("");
        );
    char find_word[102];
    scanf("%s ", find_word);
    while (strcmp(find_word, "0") != 0)
    {
        words.push_back(find_word);
        scanf("%s ", find_word);
    }
    
    return true;
}

bool check_match(int x, int y, direction pos, string word, int char_pos, int& l, int& m)
{
    debug(word, TAB); debug(word[char_pos], TAB); debug(matrix[x][y], endl);
    if (word[char_pos] == matrix[x][y] && char_pos == word.length()-1)
    {
        l = x;
        m = y;
        return true;
    }
    else if (word[char_pos] != matrix[x][y]) return false;

    return check_match(x+movx[pos], y+movy[pos], pos, word, char_pos+1, l, m);
}

void prune()
{
    string w;
    vector<string>::iterator it;
    REP(i, (int) words.size())
    {
        w = words[i];
        reverse(w.begin(), w.end());
        if ((it = find(words.begin()+i+1, words.end(), w)) != words.end())
        {
            *it = "0";
        }

    }

    REP(i, (int)words.size())
    {
        cout << words[i] << endl;
    }
    puts("");
}

void process()
{
    
    //process input
    dbg(
    dump();
        );
    bool is_match = false;
    int j, k, l, m;
    REP(i, (int)words.size())
    {
        for (j = 1; j < len+1; ++j)
        {
            for (k = 1; k < len+1; ++k)
            {
                if (matrix[j][k] == words[i][0])
                {
                    if (words[i].length() == 1)
                    {
                        l = m = j = k;
                        is_match = true;
                        break;
                    }
                    debug(j, TAB); debug(k, endl);
                    if (check_match(j+movx[EAST], k+movy[EAST], EAST, words[i], 1, l, m) || 
                        check_match(j+movx[NORTHEAST], k+movy[NORTHEAST], NORTHEAST, words[i], 1, l, m) || 
                        check_match(j+movx[NORTH], k+movy[NORTH], NORTH, words[i], 1, l, m) || 
                        check_match(j+movx[NORTHWEST], k+movy[NORTHWEST], NORTHWEST, words[i], 1, l, m) || 
                        check_match(j+movx[WEST], k+movy[WEST], WEST, words[i], 1, l, m) || 
                        check_match(j+movx[SOUTHWEST], k+movy[SOUTHWEST], SOUTHWEST, words[i], 1, l, m) || 
                        check_match(j+movx[SOUTH], k+movy[SOUTH], SOUTH, words[i], 1, l, m) || 
                        check_match(j+movx[SOUTHEAST], k+movy[SOUTHEAST], SOUTHEAST, words[i], 1, l, m))
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
            printf("%d,%d %d,%d", j, k, l, m);
        else
            printf("Not Found");
        
        puts("");
        is_match = false;
    }
}

int main()
{
    CL2d(matrix, 0, mxlen+2, mxlen+2);
    //while ()
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
