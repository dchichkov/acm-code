import java.util.*;

/**
 * Author: Matthew Gavin
 * Date: 2/26/2012
 * Problem: Deloitte Contest - Problem 6: Connect 4
 * Description: Using floodfill to solve the problem,check 4 distinct directions
 * Prof. Isaac Traxler
 * Compiled with: javac connectfour_Deloitte_6.java
 * Compiler: javac 1.6.0_18
 * Comments: This took like 2 hours. The gotcha was incorporating for the distinction
 *           in which direction you checked for connecting Os.
 */


public class connectfour_Deloitte_6
{
    private static char[][] grid = new char[9][11];
    private static int[] checkx = { 1, 1, 0, -1, -1, -1, 0, 1};
    private static int[] checky = { 0, 1, 1, 1, 0, -1, -1, -1};

    private static int[][] checkx1 = {{-1, 1}, //0 = left right
                                      {0, 0}, //1 = up down
                                      {-1, 1}, // 2 = diagonal left
                                      {1, -1}};//3 = diagonal right

    
    private static int[][] checky1 = {{0, 0},
                                      {1, -1},
                                      {1, -1},
                                      {1, -1}};


    private static int count = 0;
    private static boolean check = false;

    private static Scanner input = new Scanner(System.in);

    private static LinkedList<Integer> answers = new LinkedList<Integer>();

    private static void resetGrid()
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 11; ++j)
            {
                if (grid[i][j] == 'Z')
                    grid[i][j] = 'O';
            }
        }
    }
    
    private static void getGrid()
    {
        String temp;
        temp = input.nextLine();

        for (int i = 1; temp.indexOf('-') == -1; ++i)
        {
            for (int j = 0; j < temp.length(); ++j)
            {
                grid[i][j+1] = temp.charAt(j);
            }
            temp = input.nextLine();
        }
    }
    
    private static void floodfill(int x, int y)
    {
        for (int i = 0; i < 8; ++i)
        {
            if (grid[x+checkx[i]][y+checky[i]] == ' ')
            {
                grid[x+checkx[i]][y+checky[i]] = 'Y';
                floodfill(x+checkx[i], y+checky[i]);
            }
        }
    }

    private static void dump()
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 11; ++j)
            {
                System.out.print(grid[i][j]);
            }
            System.out.println();
        }
    }

    private static void floodCheckUD(int x, int y)
    {

        for (int j = 0; j < 2; ++j)
        {
            if (grid[x+checkx1[1][j]][y+checky1[1][j]] == 'O')
            {
                count++;
                grid[x+checkx1[1][j]][y+checky1[1][j]] = 'Z';
                floodCheckUD(x+checkx1[1][j], y+checky1[1][j]);
            }
        }
    }

    private static void floodCheckLR(int x, int y)
    {

        for (int j = 0; j < 2; ++j)
        {
            if (grid[x+checkx1[0][j]][y+checky1[0][j]] == 'O')
            {
                count++;
                grid[x+checkx1[0][j]][y+checky1[0][j]] = 'Z';
                floodCheckLR(x+checkx1[0][j], y+checky1[0][j]);
            }
        }
    }

    //BS == backslash
    private static void floodCheckBS(int x, int y)
    {

        for (int j = 0; j < 2; ++j)
        {
            if (grid[x+checkx1[2][j]][y+checky1[2][j]] == 'O')
            {
                count++;
                grid[x+checkx1[2][j]][y+checky1[2][j]] = 'Z';
                floodCheckBS(x+checkx1[2][j], y+checky1[2][j]);
            }
        }
    }

    //FS == forward slash
    private static void floodCheckFS(int x, int y)
    {

        for (int j = 0; j < 2; ++j)
        {
            if (grid[x+checkx1[3][j]][y+checky1[3][j]] == 'O')
            {
                count++;
                grid[x+checkx1[3][j]][y+checky1[3][j]] = 'Z';
                floodCheckFS(x+checkx1[3][j], y+checky1[3][j]);
            }
        }
    }

    public static void main(String args[])
    {
        while (input.nextLine().indexOf("@") == -1)
        {
            getGrid();

            for (int i = 7; i >= 1; --i)
            {
                for (int j = 9; j >= 1; --j)
                {
                    if (grid[i][j] == 'O')
                        floodfill(i, j);
                }
            }
            //dump();


            for (int i = 1; i < 8; ++i)
            {
                int j;
                for (j = 1; j < 10; ++j)
                {
                    if (grid[i][j] == 'Y')
                    {
                        grid[i][j] = (char)(j+0x30);
                        floodCheckUD(i, j);                        

                        if (count >= 3)
                        {
                            check = true;
                            //dump();
                           
                        }
                        count = 0;
                        resetGrid();

                        floodCheckLR(i, j);
                        if (count >= 3)
                        {
                            check = true;
                            //dump();
                           
                        }
                        count = 0;
                        resetGrid();
                        floodCheckBS(i, j);
                        if (count >= 3)
                        {
                            //dump();
                            check = true;
                            
                        }
                        count = 0;
                        resetGrid();
                        floodCheckFS(i, j);
                        if (count >= 3)
                        {
                            check = true;
                            //dump();
                            
                        }
                        count = 0;
                        resetGrid();
                        
                    }
                    if (check)
                    {
                        answers.add(j-1);
                        check = false;
                    }
                }
                resetGrid();
                
                count = 0;
            }

            if (answers.size() == 0)
                System.out.print("No");
            else
                System.out.print("Yes ");
                
            while (answers.size() != 0)
            {
                
                System.out.print(answers.remove());
                if (answers.size() > 0)
                    System.out.print(",");
            }
            System.out.println();
            
        }

    }

}