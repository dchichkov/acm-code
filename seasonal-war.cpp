/*
 * Author: Matthew Gavin
 * Date: 2/5/2012
 * Problem: Seasonal War UVA-352
 * Description: Using floodfill to solve the problem.
 * Prof. Isaac Traxler
 * Compiled with: g++ seasonal-war.cpp -o war
 * 
 */

#include <iostream>
#include <string>

using namespace std;

int xchecks[] = {1, 1, 0, -1, -1, -1,  0,  1};
int ychecks[] = {0, 1, 1,  1,  0, -1, -1, -1};

int grid[26][26];

void makegrid(int r)
{
  for (int i =0; i < r+2; ++i)
    for (int j = 0; j < r+2; ++j)
      grid[i][j] = 0;

  string temp;

  while (cin.peek() == '\n' || cin.peek() == '\r')
    cin.get();
  
  for (int i = 1; i < r+1; ++i)
    {
      getline(cin, temp);

      for (int j = 1; j < temp.size()+1; ++j)
        {

          grid[i][j] = temp[j-1] - 0x30;
        }

    }
}
        
void floodfill(int x, int y)
{

  for (int i = 0; i < 8; ++i)
    {
      if (grid[x+xchecks[i]][y+ychecks[i]] == 1)
        {
          grid[x+xchecks[i]][y+ychecks[i]] = -1;
          floodfill(x+xchecks[i], y+ychecks[i]);
        }
    }
}

int main()
{
  int num, inc = 0;

  cin >> num;

  while (!cin.eof())
    {
      makegrid(num);

      int cnt = 0;
      /*
      for (int i = 0; i < num+2; ++i)
        {
          for (int j = 0; j < num+2; ++j)
            {
              cout << grid[i][j];
            }
          cout << endl;

       }*/
      for (int i = 0; i < num+1; ++i)
        for (int j = 0; j < num+1; ++j)
          {
            if (grid[i][j] == 1)
              {
                ++cnt;
                grid[i][j] = -1;
                floodfill(i, j);
              }
          }

      cout << "Image number " << ++inc << " contains " << cnt << " war eagles." << endl;

      cin >> num;
    }

  return 0;
}
