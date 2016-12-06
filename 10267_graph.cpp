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
char sheet[255][255];
char line[100];
int tbl_l;
int tbl_w;
int movx[] = {1, 0, -1, 0};
int movy[] = {0, 1, 0, -1};
/*global variables*/

void dump()
{
    //dump data
    FOR(i, 0, tbl_l+2)
    {
        FOR(j, 0, tbl_w+2)
        {
            printf("%c", sheet[i][j]);
        }
        puts("");
    }
}

bool getInput()
{
    //get input
    fgets(line, 100, stdin);
    if (line[strlen(line)-1] == '\n')
        line[strlen(line)-1] = 0;
    debug(line, endl);
    if (strcmp(line, "X") == 0) return false;
    return true;
}

void fill(int x, int y, char color, char pcolor)
{
    sheet[x][y] = color;
    REP(i, 4)
    {
        if (sheet[x+movx[i]][y+movy[i]] == pcolor)
        {
            fill(x+movx[i], y+movy[i], color, pcolor);
        }
    }
}

void clear()
{
    CL2d(sheet, 'O', 255, 255);
    FOR(i, 0, tbl_w+2)
    {
        sheet[0][i] = 0;
    }
    FOR(i, 0, tbl_l+2)
    {
        sheet[i][0] = 0;
    }
    FOR(i, 0, tbl_w+2)
    {
        sheet[tbl_l+1][i] = 0;
    }
    FOR(i, 0, tbl_l+2)
    {
        sheet[i][tbl_w+1] = 0;
    }
}

void process()
{
    //process input
    char instruction = line[0];
    int x1, x2, y1, y2;
    char color;
    debug(instruction, endl);
    char* token;
    switch (instruction)
    {
    case 'I':
        sscanf(line, "%c %d %d ", &instruction, &x1, &x2);
        debug(line, TAB); debug(x1, TAB); debug(x2, endl);
        if (x1 < 0 || x1 > 250 || x2 < 0 || x1 > 250) break;
        tbl_w = x1;
        tbl_l = x2;
        clear();
        break;
    case 'C':
        clear();
        break;
    case 'L':
        sscanf(line, "%c %d %d %c ", &instruction, &x1, &y1, &color);
        debug(line, TAB); debug(x1, TAB); debug(y1, TAB); debug(color, endl);
        if (y1 < 1 || x1 < 1 || x1 > tbl_w || y1 > tbl_l) break;
        sheet[y1][x1] = color;
        break;
    case 'V':
        sscanf(line, "%c %d %d %d %c ", &instruction, &x1, &y1, &y2, &color);
        if (y1 < 1 || y2 > tbl_l) break;
        int tempr;
        tempr = min(y1, y2);
        y2 = max(y1, y2);
        y1 = tempr;
        FOR(i, y1, y2+1)
        {
            sheet[i][x1] = color;
        }
        break;
    case 'H':
        sscanf(line, "%c %d %d %d %c ", &instruction, &x1, &x2, &y1, &color);
        if (x2 > tbl_w || x1 < 1) break;
        int temp;
        temp = min(x1, x2);
        x2 = max(x1, x2);
        x1 = temp;
        FOR(i, x1, x2+1)
        {
            sheet[y1][i] = color;
        }
        break;
    case 'K':
        sscanf(line, "%c %d %d %d %d %c ", &instruction, &x1, &y1, &x2, &y2, &color);
        if (x1 < 1 || y1 < 1) break;
        if (x2 > tbl_w+1 || y2 > tbl_l+1) break;
        int t1, t2;
        t1 = min(x1, x2);
        x2 = max(x1, x2);
        x1 = t1;
        t2 = min(y1, y2);
        y2 = max(y1, y2);
        y1 = t2;
        FOR(i, x1, x2+1)
        {
            FOR(j, y1, y2+1)
            {
                sheet[j][i] = color;
            }
        }
        break;
    case 'F':
        sscanf(line, "%c %d %d %c ", &instruction, &x1, &y1, &color);
        if (x1 < 1 || x1 > tbl_w+1 || y1 < 1 || y1 > tbl_l+1) break;
        if (sheet[y1][x1] != color)
            fill(y1, x1, color, sheet[y1][x1]);
        break;
    case 'S':
        token = strtok(line, " ");
        token = strtok(NULL, " ");
        printf("%s\n", token);
        debug(tbl_l, TAB); debug(tbl_w, endl);
        FOR(i, 1, tbl_l+1)
        {
            FOR(j, 1, tbl_w+1)
            {
                printf("%c", sheet[i][j]);
            }
            puts("");
        }
        break;
    default:
        break;
    }
}

int main()
{
    clear();
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
