/**
 *Author: Matthew Gavin
 *Date: 2/21/2012
 *Problem: Florida Wetlands UVA-469
 *Description: Using floodfill
 *Prof: Isaac Traxler
 *Compiled with: javac floridawetlands.java
 *Compiler: 1.7.0_02
 *
 *Comments: AHHHHH WHITESPACE, ANSWER FORMATTING, INPUT!! ARGHHH
 *          FINALLYYYYYYY!!!
 */

import java.util.Scanner;

public class floridawetlands
{
    private static char[][] grid = new char[101][101];
    private static int counter = 0;

    private static final char water = 'W';
    private static final char cancel = 'X';

    private static final int[] checkx = { 0, 1, 1, 0, -1, -1, -1,  0,  1};
    private static final int[] checky = { 0, 0, 1, 1,  1,  0, -1, -1, -1};

    private static Scanner input = new Scanner(System.in);
    
    private static void getgrid()
    {
        for (int j = 0; j < 101; ++j)
            for (int k = 0; k < 101; ++k)
                grid[j][k] = '-';

        String temp;


        for (int i = 0; !input.hasNextInt(); ++i)
        {
            temp = input.nextLine();

            for (int j = 0; j < temp.length(); ++j)
            {
                grid[i][j+1] = temp.charAt(j);
            }
        }
    }

    private static void floodfill(int x, int y)
    {
        for (int i = 0; i < 9; ++i)
        {
            if (grid[x+checkx[i]][y+checky[i]] == water)
            {
                grid[x+checkx[i]][y+checky[i]] = cancel;
                counter++;
                floodfill(x+checkx[i], y+checky[i]);
            }
        }
    }

    private static void floodfill2(int x, int y)
    {
        
        for (int i = 0; i < 9; ++i)
        {
            if (grid[x+checkx[i]][y+checky[i]] == cancel)
            {
                grid[x+checkx[i]][y+checky[i]] = (char)(counter + 100); //magic number 100 not to interfere with other characters
                floodfill2(x+checkx[i], y+checky[i]);
            }            
        }
    }
    
    public static void main(String[] args)
    {
        int num = input.nextInt();
        input.skip("\n");
        
        for (int i = 0; i < num; ++i)
        {
            getgrid();
            /*
            for (int j = 0; j < 101; ++j)
            {
                for (int k = 0; k < 101; ++k)
                    System.out.print(grid[j][k]);
                System.out.println();
            }
            */
            for (int j = 0; j < 101; ++j)
                for (int k = 0; k < 101; ++k)
                {
                    if (grid[j][k] == water)
                    {
                        //grid[j][k] = cancel;
                        floodfill(j, k);
                        floodfill2(j, k); //fill with numbers
                    }
                    counter = 0;
                }
            /*
            for (int j = 0; j < 101; ++j)
            {
                for (int k = 0; k < 101; ++k)
                    System.out.print(grid[j][k]);
                System.out.println();
            }
            */
            while (input.hasNextInt())
            {
                int a = input.nextInt();
                int b = input.nextInt();
                
                if ((int)grid[a][b] == (char)0 || grid[a][b] == 'L')
                    System.out.println(0);
                else
                    System.out.println((int)grid[a][b]-100);
            }

            if (i+1 != num)
                System.out.println();
            try {
                input.skip("\n");
            }catch(Exception e){/*no new line to skip!*/}
        }
    }
}