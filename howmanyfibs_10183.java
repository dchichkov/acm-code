import java.util.*;
import java.math.*;

public class howmanyfibs_10183
{
    public static void genFibs(BigInteger[] n)
    {
        n[0] = new BigInteger("1");
        n[1] = new BigInteger("2");
        int counter = 0;
        for (int i = 2; n[i-1].toString().length() < 102; ++i)
        {
            n[i] = new BigInteger(n[i-1].add(n[i-2]).toString());
            counter++;
        }
        /*System.out.println(counter);
          System.out.println(n[counter]);*/
    }
    
    public static void main(String[] args)
    {
        BigInteger[] fibs = new BigInteger[490];
        genFibs(fibs);
        /*        System.out.println(fibs.length);*/
        Scanner input = new Scanner(System.in);
        String a, b;
        
        a = input.next();
        b = input.next();
        BigInteger c, d;
        int idx = 0;
        while (a.compareTo("0") != 0 || b.compareTo("0") != 0)
        {
            c = new BigInteger(a);
            d = new BigInteger(b);
            for (BigInteger p : fibs)
            {
                if (p != null)
                {
                    if ((p.compareTo(c) == 0 ||
                         p.compareTo(c) == 1) && (p.compareTo(d) == 0 || p.compareTo(d) == -1))
                        idx++;
                }
            }

            System.out.println(idx);
            idx = 0;
            a = input.next();
            b = input.next();
        }
        

    }

}