#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

#define DEBUG
//#undef DEBUG //uncomment this line to pull out print statements
#ifdef DEBUG
#define debug(a, end) cout << #a << ": " << a << end
#else
#define debug(a, end)
#endif

using namespace std;

#define CL2d(a,b,c) memset(a, 0, sizeof(a[0][0])*b*c)

/*global variables*/
int checkx[] = { 1,  0, -1,   0 };
int checky[] = { 0,  1,  0,  -1 } ;
char grid[40][100];
string underlines;
const char WALL = 'X';
/*global variables*/

void dump()
{
    for (int i = 1; i < 40; ++i)
    {
        for (int j = 1; j < 100 && grid[i][j] != '\0'; ++j)
        {
            printf("%c", grid[i][j]);
        }
    }
}

bool getInput()
{
    CL2d(grid, 40, 100);
    
    char line[100];
    bool end_input = false;
    for (int i = 1; i < 34; ++i)
    {
        if (fgets(line, 100, stdin) == NULL)
        {
            end_input = true;
            break;
        }
        strcpy(&grid[i][1], line);
        if (strchr(line, '_') != NULL)
            break;
    }

    if (end_input) return false;
    return true;
}

void floodfill(int x, int y, char c)
{
    for (int i = 0; i < 4; ++i)
    {
      if (grid[x+checkx[i]][y+checky[i]] == ' ')
	  {
		grid[x+checkx[i]][y+checky[i]] = c;
		floodfill(x+checkx[i], y+checky[i], c);
	  }
    }
}

void process()
{
    char c, contour = 0;
    for (int i = 1; i < 39; ++i)
        for (int j = 1; j < 100 && grid[i][j] != '\0'; ++j)
        {
            if (grid[i][j] != ' ' && grid[i][j] != '_' && grid[i][j] != '\n')
            {
                if (!contour)
                    contour = grid[i][j];
                else if (grid[i][j] != contour)
                {
                    c = grid[i][j];
                    floodfill(i, j, c);
                }
            }
        }
}


int main()
{
    bool moreToDo = true;
    while (moreToDo)
    {
        moreToDo = getInput();
        process();
        dump();
    }

    return 0;
}
