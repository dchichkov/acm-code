#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <cfloat>
#include <cctype>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue> 
#include <regex.h> 

#define DEBUG
//#undef DEBUG //uncomment this line to pull out print statements
#ifdef DEBUG
#define print(a, end) cout << #a << ": " << a << end
#else
#define print(a, end)
#endif

using namespace std;

/*global variables*/

char grid[202][202];
int checkx[] = { 1,  0,  -1,  0, 1, -1, -1, 1 };
int checky[] = { 0,  1,  0,  -1, 1, 1, -1, -1 };
int counter = numeric_limits<int>::max();

queue<pair<int, int> > coordinates; //for BFS
queue<pair<int, int> > jiggles;
/*global variables*/

void formPerimeter(int x, int y, int multiplier)
{
    
}

void formPerimeter2(int x, int y, int multiplier)
{
    for (int i = max(1, x-multiplier); i <= min(200, x+multiplier); ++i)
    {
        for (int j = max(1, y-multiplier); j <= min(200, y+multiplier); ++j)
        {
            if (i == x && j == y) continue;
            if ((sqrt(pow(x-i, 2) + pow(y-j, 2))) <= multiplier)
                grid[i][j] = 'l';
        }
    }
}

void getInput(int rows, int cols)
{
    //clear grid
    for (int i = 0; i < 202; ++i)
        for (int j = 0; j < 202; ++j)
            grid[i][j] = '-';

    for (int i = 1; i <= rows; ++i)
        for (int j = 1; j <= cols; ++j)
            grid[i][j] = ' ';
    grid[rows][cols] = 'E';
    //get input
    int blockedCoords = 0;
    int x, y;
    cin >> blockedCoords;
    for (int i = 0; i < blockedCoords; ++i)
    {
        cin >> x >> y;
        grid[x][y] = 'b';
    }

    //get jiggopuffs
    int jigCoords = 0;
    int loud = 0;
    cin >> jigCoords;
    for (int i = 0; i < jigCoords; ++i)
    {
        cin >> x >> y >> loud;
        grid[x][y] = 'j';
        formPerimeter2(x, y, loud);
    }
}



void floodfill(int x, int y, int num)
{
    pair<int, int> open_space;
    
    for (int i = 0; i < 4; ++i)
    {
        if (grid[x+checkx[i]][y+checky[i]] == 'E')
            counter = min(counter, num);
        if (grid[x+checkx[i]][y+checky[i]] == ' ' || grid[x+checkx[i]][y+checky[i]] == 'E')
        {
            grid[x+checkx[i]][y+checky[i]] = num;
            open_space.first = x+checkx[i];
            open_space.second = y+checky[i];
            coordinates.push(open_space);
        }

    }
    while (!coordinates.empty())
    {
        open_space = coordinates.front();
        coordinates.pop();
        floodfill(open_space.first, open_space.second, grid[open_space.first][open_space.second]+1);
    }
}

void process()
{
    //process input
    //go from the top left
    if (grid[1][1] == 'b' || grid[1][1] == 'j' || grid[1][1] == 'l')
      return;
    grid[1][1] = 0;
    floodfill(1, 1, 1);
}

void dump(int rows, int cols)
{
    for (int i = 0; i <= rows+1; ++i)
    {
        for (int j = 0; j <= cols+1; ++j)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

int main()
{
    //getline(cin, temp);
    bool moreToDo;
    int rows = 0;
    int cols = 0;
    cin >> rows >> cols;
    while (moreToDo = (rows != 0 && cols != 0))
    {

        getInput(rows, cols);
        //dump(rows, cols);

        process();
        //dump(rows, cols);
        /*output*/
        if (counter != numeric_limits<int>::max())
            cout << counter << endl;
        else
            cout << "Impossible." << endl;

        /*output*/

        counter = numeric_limits<int>::max();
        cin >> rows >> cols;
    }
}
