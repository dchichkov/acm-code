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
int checkx[] = { 1,  0,  -1,   0  };
int checky[] = { 0,  1,    0,  -1 } ;
int checkx2[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int checky2[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int numLines = 0;
char grid[35][82];
string underlines;
char WALL;
/*global variables*/

void getInput()
{
    //get input
    int p = 1;
  
    for (int i = 0; i < 32; ++i)
        for (int j = 0; j < 82; ++j)
            grid[i][j] = ' ';

    string temp;
    getline(cin, temp);
    
    while (temp.find("_") == string::npos && p < 34)
    { 
        for (int z = 0; z < temp.size() && z < 81; ++z)
            grid[p][z+1] = temp[z];
        //grid[p][temp.size()+1] = '\0';
        getline(cin, temp);
        ++p;
    }
    underlines = temp;
    numLines = p-1;
}

bool isWall(int x, int y)
{
    for (int i = 0; i < 8; ++i)
    {
        if (grid[x+checkx2[i]][y+checky2[i]] == '_')
        {
			WALL = grid[x][y];
			return true;
		}
    }

    return false;
}



void floodfill(int x, int y, char c)
{
    for (int i = 0; i < 4; ++i)
    {
      if (x+checkx[i] < 0 || x+checkx[i] > 31 ||
		  y+checky[i] < 0 || y+checky[i] > 81)
		continue;
      if (grid[x+checkx[i]][y+checky[i]] == ' ')
	  {
		grid[x+checkx[i]][y+checky[i]] = c;
		floodfill(x+checkx[i], y+checky[i], c);
	  }
    }
}

void process()
{
    //process input
    char c;
    //floodfill the outside
    floodfill(0, 0, '_');

    for (int i = 1; i <= numLines; ++i)
        for (int j = 1; grid[i][j] != '\0'; ++j)
        {
            if (grid[i][j] != ' ' && !isWall(i, j) && grid[i][j] != WALL)
            {
                c = grid[i][j];
                floodfill(i, j, c);
            }
        }
}


int main()
{
    string temp;
    //getline(cin, temp);
    bool moreToDo = true;;
    while (moreToDo = !cin.eof()) //more to do, however you want to express end of input
    {
        getInput();
		/*
        for (int i = 1; i <= numLines; ++i)
        {
            string output;
            for (int j = 1; grid[i][j] != '\0' && j < 81; ++j)
                output += grid[i][j];
            cout << output << endl;
			
        }
		*/
        process();
		

        /*output*/
        for (int i = 1; i <= numLines; ++i)
        {
            string output;
            for (int j = 1; grid[i][j] != '\0' && j < 81; ++j)
                output += grid[i][j];
            for (int j = 0; j < output.length(); ++j)
                if (output.at(j) == '_')
                    output.at(j) = ' ';
			cout << output;
			//	if (i != numLines)
				cout << endl;
        }
        /*output*/
		cout << underlines << endl;
		do
		{
			getline(cin, temp);
			cout << temp << endl;
        } while (temp.find(" ") != string::npos &&  temp.find("_") != string::npos && !cin.eof());
        
        numLines = 0;
		WALL = ' ';
    }

    return 0;
}
