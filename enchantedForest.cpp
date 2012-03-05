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
int checkx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int checky[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
queue<pair<int, int> > coordinates; //for BFS
/*global variables*/

void getInput()
{
    //get input
    int jigCoords = 0;
    int x, y;
    cin >> jigCoords;
    for (int i = 0; i < jigCoords; ++i)
    {
        cin >> x >> y;
        grid[x][u] = 'j';
    }

    
}

void floodfill(int x, int y, int multiplier)
{
    for (int i = 0; i < 8; ++i)
    {
        
    }
}

void process()
{
    //process input
}

int main()
{
    //getline(cin, temp);
    bool moreToDo;
    int rows = 1;
    int cols = 1;
    
    while (moreToDo = (rows != 0 && cols != 0))
    {
        cin >> rows >> cols;
        getInput();

        process();

        /*output*/


        /*output*/
    }
}
