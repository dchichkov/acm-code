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
char grid[152][152];
int x, y;
int checkx[] = {};
int checky[] = {};
/*global variables*/

/*
void floodfill(int x, int y)
{
    for (int i = 0; i < 8; ++i)
    {
        //character logic


        //---
        if (grid[x+checkx[i]][y+checky[i]] == '') //go on
        {
            floodfill(x+checkx[i], y+checky[i]);
        }
    }
}
*/

void dump()
{
    //dump data

    for (int i = 1; i < 152; ++i)
    {
        for (int j = 1; j < 152; ++j)
            cout << grid[i][j];

        
        cout << endl;
        string a(grid[i]);
        if (a.find_first_not_of("-") == string::npos) break;
    }
}

bool getInput()
{
    //get input
    //clear the grid
    for (int i = 0; i < 152; ++i)
        for (int j = 0; j < 152; ++j)
            grid[i][j] = '-';

    string temp;
    cin >> y >> x;
    cin.ignore(); //new line

    if (x == 0 && y == 0)
        return false;

    print(x, "\t"); print(y, endl);
    for (int i = 1; i < x+1; ++i)
    {
        getline(cin, temp);


        for (int j = i, pos = 0; j < y+i;  ++pos)
        {
            if (temp[pos] == '/')
            {
                grid[i][j] = '|';
                grid[i][j+1] = ' ';
                j+=2;
            }
            else
            {
                grid[i][j] = '_';
                j++;
            }
        }
    }
    
    return true;
}

void process()
{
    //process input
}

int main()
{
    bool moreToDo;
    while (moreToDo = getInput())
    {
        dump();

        process();

        /*output*/


        /*output*/
    }
}
