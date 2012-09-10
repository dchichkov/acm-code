/**
 * Author: Matthew Gavin
 * Date: 9/5/2012
 * Problem: 10862 - Connect the Cable Wires
 * Description: Got the answer from ->
 *              https://www.comp.nus.edu.sg/~stevenha/programming/volC8.html#10862_-_Connect_the_Cable_Wires
 *              
 *              Although I'm not sure how that was derived... it would be nice if someone could understand the theory behind it.
 *              Whatever. There's no way trying to generate the numbers through fibonacci would've worked. Apparently
 *              the discussion board provided good hints, but I don't understand what they're saying most of the time. Oh
 *              well.
 *              
 * Prof. Isaac Traxler
 * Compiled with: javac concab_10862.java
 * Compiler: javac 1.6.0_24
 */

import java.util.*;
import java.math.*;

public class concab_10862
{
    
    public static void main(String[] args)
    {
        //do fib precompute; actually...
        Scanner input = new Scanner(System.in);
        //BigInteger num = input.nextBigInteger();
        int num = input.nextInt();

        BigInteger[] fibs = new BigInteger[2000];
        
        fibs[0] = new BigInteger("1");
        fibs[1] = new BigInteger("3");
        for (int i = 2; i < 2000; ++i)
        {
            fibs[i] = new BigInteger("3").multiply(fibs[i-1]).subtract(fibs[i-2]);
        }

        while (num != 0)
        {
            System.out.println(fibs[num-1]);
            num = input.nextInt();
        }
    }
}