#include <iostream>
#include <string>

using namespace std;

int xchecks[] = { 1, 1, 0, -1, -1, -1,  0,  1};
int ychecks[] = { 0, 1, 1,  1,  0, -1, -1, -1};

char grid[31][81] = {0};

void makegrid()
{
  int p = 1;
  
  for (int i = 0; i < 31; ++i)
    for (int j = 0; j < 81; ++j)
      grid[i][j] = 0;

  string temp;

  getline(cin, temp);
  while (temp.find_first_not_of("_") == string::npos)
    { 
      for (int z = 1; z < temp.size(); ++z)
            grid[p][z] = temp[z-1];
      getline(cin, temp);
      ++p;
    }
}

void floodfill(int x, int y, char c)
{

  for (int i = 0; i < 8; ++i)
    {
      if (grid[x+xchecks[i]][y+ychecks[i]] != ' ')
        {
          grid[x+xchecks[i]][y+ychecks[i]] = c;
          floodfill(x+xchecks[i], y+ychecks[i], c);
        }
    }
}

int main()
{
  while (!cin.eof())
    {
      makegrid();
      char c;
      for (int i = 0; i < 30; ++i)
        for (int j = 0; j < 80; ++j)
          {
            if (grid[i][j] != 'X' || grid[i][j] != ' ')
              {
                c = grid[i][j];
                floodfill(i, j, c);
              }
          }

      for (int i = 0; i < 30; ++i)
        {
          for (int j = 0; j < 80; ++j)
            {
              cout << grid[i][j];
            }
          cout << endl;
        }

      break;
    }

  return 0;
}

      
