
#include <iostream>
#include <string>

using namespace std;

int xchecks[] = { 1, 1, 0, -1, -1, -1,  0,  1};
int ychecks[] = { 0, 1, 1,  1,  0, -1, -1, -1};

char grid[101][101];

void makegrid(int r, int c)
{
  for (int i = 0; i < 101; ++i)
    for (int j = 0; j < 101; ++j)
      grid[i][j] = 0;
  
  for (int i = 0; i < r+2; ++i)
    for (int j = 0; j < c+2; ++j)
      grid[i][j] = '?';

  string temp;

  //  getline(cin, temp);
  while (cin.peek() == '\n' || cin.peek() == '\r')
    cin.get();
  for (int i = 1; i < r+1; ++i)
    {
      getline(cin, temp);
      for (int z = 1; z < temp.size()+1; ++z)
        {
          if (temp[z-1] == '*' || temp[z-1] == '@')
            grid[i][z] = temp[z-1];
        }
    }
}

void floodfill(int x, int y)
{

  for (int i = 0; i < 8; ++i)
    {
      if (grid[x+xchecks[i]][y+ychecks[i]] == '@')
        {
          grid[x+xchecks[i]][y+ychecks[i]] = '-';
          floodfill(x+xchecks[i], y+ychecks[i]);
        }
    }
}
          

int main(int argc, char* argv[])
{
  int cols, rows;

  cin >> cols >> rows;

  while (cols != 0 && rows != 0)
    {
      makegrid(rows, cols);

      int cnt = 0;
      /*
      for (int i = 0; i < rows+2; ++i)
        {
          for (int j = 0; j < cols+2; ++j)
            {
              cout << grid[i][j];
            }
          cout << endl;
          }*/
      
      for (int i = 0; i < rows+1; ++i)
        {        
          for (int j = 0; j < cols+1; ++j)
            {
              if (grid[i][j] == '@')
                {
                  ++cnt;
                  grid[i][j] = '-';
                  floodfill(i, j);
                }
            }
        }
      /*
      for (int i = 0; i < rows+2; ++i)
        {
          for (int j = 0; j < cols+2; ++j)
            {
              cout << grid[i][j];
            }
          cout << endl;
          }*/
      cout << cnt << endl;
      
      cin >> rows >> cols;

      //cout << rows << " " << cols << endl;

    }

  return 0;
}
