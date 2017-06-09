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
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,(int)n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
char puzzle[7][7];
int x, y;
bool first = true;
char line[2000];
/*global variables*/

void dump()
{
    //dump data
    FOR(i, 0, 7)
    {
        FOR(j, 0, 7)
        {
            if (j != 0) printf(" ");
            //output final board
            printf("%c", puzzle[i][j]);
        }
        puts("");
    }
    puts("");
}

bool getInput()
{
    //get input
    //"The end of data is denoted by the character Z." OR NOT
    //read first c
    int i = 1, j = 1;
    CL2d(puzzle, 0, 7, 7);
    fgets(line, 2000, stdin);
    debug(line, endl);
    if (line[0] == 'Z' && strlen(line) == 2) return false;

    puzzle[i][j] = line[0];
    puzzle[i][j+1] = line[1];
    puzzle[i][j+2] = line[2];
    puzzle[i][j+3] = line[3];
    puzzle[i][j+4] = line[4];
    ++i;
    for (; i < 6; ++i)
    {
        fgets(line, 2000, stdin);
        puzzle[i][j] = line[0];
        puzzle[i][j+1] = line[1];
        puzzle[i][j+2] = line[2];
        puzzle[i][j+3] = line[3];
        puzzle[i][j+4] = line[4];
    }
    FOR(i, 1, 6)
    {
        FOR(j, 1, 6)
        {
            if (puzzle[i][j] == ' ')
            {
                x = i;
                y = j;
            }
        }
    }
                
    dbg ( dump() );
    return true;
}

void process()
{
    //process input
    debug(x, TAB); debug(y, endl);
    while (line[strlen(line)-1] != '0')
    {
        //process commands
        fgets(line, 2000, stdin);
        debug(line, endl);
        for (int i = strlen(line)-1; i > 0; --i)
        {
            if (line[i] == ' ' || line[i] == '\n')
                line[i] = 0;
            else
                break;
        }
        REP(i, strlen(line))
        {
            if (line[i] == '\n' ||
                line[i] == '0' ||
                line[i] == ' ' ||
                (line[i] < 0x40 || line[i] > 0x5A)) continue; //NOT DESCRIBED IN INPUT.

            switch (line[i])
            {
            case 'A':
                if (puzzle[x-1][y] == 0)
                    goto error;
                puzzle[x][y] = puzzle[x-1][y];
                x -= 1;
                break;
            case 'B':
                if (puzzle[x+1][y] == 0)
                    goto error;
                puzzle[x][y] = puzzle[x+1][y];
                x += 1;
                break;
            case 'L':
                if (puzzle[x][y-1] == 0)
                    goto error;
                puzzle[x][y] = puzzle[x][y-1];
                y -= 1;
                break;
            case 'R':
                if (puzzle[x][y+1] == 0)
                    goto error;
                puzzle[x][y] = puzzle[x][y+1];
                y += 1;
                break;
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':
            case 'H':
            case 'I':
            case 'J':
            case 'K':
            case 'M':
            case 'O':
            case 'P':
            case 'Q':
            case 'S':
            case 'T':
            case 'U':
            case 'V':
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':                
                goto error;
                break;
            }
            puzzle[x][y] = ' ';
        }
    }

    FOR(i, 1, 6)
    {
        FOR(j, 1, 6)
        {
            if (j != 1) printf(" ");
            //output final board
            printf("%c", puzzle[i][j]);
        }
        puts("");
    }
    goto noerror;
    
error:
    printf("This puzzle has no final configuration.\n");

    while (line[strlen(line)-1] != '0')
    {
        fgets(line, 2000, stdin);
        debug(line, endl);
        for (int i = strlen(line)-1; i > 0; --i)
        {
            if (line[i] == ' ' || line[i] == '\n')
                line[i] = 0;
            else
                break;
        }
    }

noerror:
    ;
}

int main()
{
    int nc = 1;

    while (getInput())
    {
        if (!first) puts("");
        printf("Puzzle #%d:\n", nc++);
        process();
        first = false;
        /*CLEAR GLOBAL VARIABLES!*/
        CL2d(puzzle, 0, 7, 7);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
