
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
int checky[] = { -1, -1, 0, 0, 1, 1 };
int checkx[] = { -1, 0, -1, 1, 0, 1 };
/*global variables*/

void getInput()
{
    //clear input
    for (int i = 0; i < 202; ++i)
        for (int j = 0; j < 202; ++j)
            grid[i][j] = 0;
    
    //get input
    string temp;

    for (int i = 1; i < 201 && !isdigit(cin.peek()); ++i)
    {
        getline(cin, temp);
        for (int j = 0; j < temp.size(); ++j)
        {
            grid[i][j+1] = temp[j];
        }
    }
        
}

bool floodfill(int x, int y, int boardSize, char color)
{
    grid[x][y] = color+1;
    for (int i = 0; i < 6; ++i)
    {
        if (grid[x+checkx[i]][y+checky[i]] == color)
        {
            grid[x+checkx[i]][y+checky[i]] = color+1;
            floodfill(x+checkx[i], y+checky[i], boardSize, color);
        }
    }
    return false;
}

char process(int boardSize)
{
    //process input
    //check white

    for (int i = 1; i <= boardSize; i++)
    {
        if (grid[i][1] == 'w')
            floodfill(i, 1, boardSize, 'w');
        
    }
    for (int j = 0; j < boardSize; ++j)
    {
        if (grid[j+1][boardSize] == 'w'+1)
            return 'w';
    }
    //else
    return 'b';
}

int main()
{
    //getline(cin, temp);
    bool moreToDo;
    int boardSize, count = 0;
    cin >> boardSize;

    while (moreToDo == (boardSize == 0))
    {

        cin.ignore(1,'\n');

        getInput();

        char winner = process(boardSize);
        
        /*output*/
        cout << ++count << " " << (char)toupper(winner) << endl;

        /*output*/
        cin >> boardSize;
    }
}
