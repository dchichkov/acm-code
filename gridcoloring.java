import java.util.Scanner;

public class gridcoloring
{
    private static final int[] checkx = {1,  0,  -1,   0};
    private static final int[] checky = {0,  1,   0,  -1};

    private static char[][] grid = new char[32][82];
	
    private static Scanner input = new Scanner(System.in);
	
    private static final char FOUND = ' ';
    private static char WALL = (char)0;
    private static char BLOCK;
	
    private static void getgrid()
    {
        //clear grid
        for (int i = 0; i < 32; ++i)
            for (int j = 0; j < 82; ++j)
                grid[i][j] = 0;
	
        String temp;
        temp = input.nextLine();
        for (int i = 1; !temp.trim().isEmpty(); ++i)
        {
            //System.out.println(temp);
            for (int j = 0; j < temp.length(); ++j)
            {

                grid[i][j+1] = temp.charAt(j);
                //             System.out.print(grid[i][j+1]);
            }
            if (!input.hasNextLine()) break;
            else
                temp = input.nextLine();
        }
			
    }
	
    private static void floodfill(int x, int y)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (grid[x+checkx[i]][y+checky[i]] == FOUND)
            {
                grid[x+checkx[i]][y+checky[i]] = BLOCK;
                floodfill(x+checkx[i],y+checky[i]);
            }
        }
    }
		
    public static void main(String[] args)
    {
        while (input.hasNextLine())
        {
            getgrid();
            for ( int i = 1; i < 31; ++i)
            {
                for (int j = 1; j < 81; ++j)
                {
                    if (WALL == (char)0 && grid[i][j] != FOUND)
                    {
                        WALL = grid[i][j];
                        continue;
                    }

                    if (grid[i][j] != FOUND && grid[i][j] != WALL
                        && grid[i][j] != 0)
                    {
                        BLOCK = grid[i][j];
                        floodfill(i, j);
                        //BLOCK = ' ';
                        WALL = (char)0;
                        while(grid[i][j]!=BLOCK)j++;
                    }

                }
            }
	
	
            for (int i = 1; i < 32; ++i)
            {
                String out = new String(grid[i]);
                System.out.println(out.substring(1));

                if (out.trim().isEmpty())
                    break;
            }

            System.out.println();
            BLOCK = ' ';
            WALL = (char)0;
        }
    }
}