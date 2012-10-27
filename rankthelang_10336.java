/**
 * Source originally written by Austin Howick
 * but I made a slight modification to his non-working code (WA on UVA)
 * and got AC with it... so I'll put it in my repository :)
 *
 * Thanks Austin!
 */


import java.util.Hashtable;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class rankthelang_10336
{

  public static void floodFill(int row, int col, char item)
  {
    image[row][col] = '0';
    for (int i = 0; i < 4; i++)
      if (image[row + rowOffset[i]][col + colOffset[i]] == item)
        floodFill(row + rowOffset[i], col + colOffset[i], item);
  }

  public static char[][] image;
  public static int[] rowOffset = { 1, 0, -1, 0 };
  public static int[] colOffset = { 0, 1, 0, -1 };
  public static Hashtable<Character, Integer> languages;
  public static Hashtable<Integer, ArrayList<Character>> counted;

  public static void main(String[] args)
  {
    Scanner in = new Scanner(System.in);
    int count = 0, rowdim, columndim, total = in.nextInt();
    char item;
    while (count < total)
    {
      /* initialize */
      rowdim = in.nextInt();
      columndim = in.nextInt();
      image = new char[rowdim + 2][columndim + 2];
      languages = new Hashtable<Character, Integer>();
      counted = new Hashtable<Integer, ArrayList<Character>>();
      for (char[] row : image)
        for (char col : row)
          col = '0';

      /* process */
      for (int row = 1; row < rowdim + 1; row++)
      {
        String line = in.next();
        for (int col = 1; col < columndim + 1; col++)
          image[row][col] = line.charAt(col - 1);
      }
      for (int row = 1; row < rowdim + 1; row++)
        for (int col = 1; col < columndim + 1; col++)
          if (image[row][col] != '0')
          {
            item = image[row][col];
            if (!languages.containsKey(item))
              languages.put(item, 1);
            else
              languages.put(item, languages.get(item) + 1);
            floodFill(row, col, item);
          }

      /* output and restart */
      System.out.println("World #" + (count + 1));
      for (char i : languages.keySet())
      {
			  if (!counted.containsKey(languages.get(i)))
			  {
					  counted.put(languages.get(i), new ArrayList<Character>());
					  counted.get(languages.get(i)).add(i);
			  }
			  else					  
					  counted.get(languages.get(i)).add(i);
	  }
	  for (Integer i : counted.keySet())
	  {
			  Collections.sort(counted.get(i));
			  for (Character c : counted.get(i))
			  {
					  System.out.println(c + ": " + i);
			  }
	  }
      count++;
    }
  }
}
