import java.util.*;
import java.math.*;

public class ghost_10992
{

    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        BigInteger a,
            b = new BigInteger("2"),
            c = new BigInteger("5"),
            d = new BigInteger("7"),
            e = new BigInteger("11"),
            f = new BigInteger("15"),
            g = new BigInteger("20"),
            h = new BigInteger("28"),
            i = new BigInteger("36"),
            j = new BigInteger("4"),
            k = new BigInteger("100"),
            l = new BigInteger("400"),
            m = new BigInteger("2148"),
            n;
        
        a = in.nextBigInteger();
        int omg = 0;
        while (a.compareTo(BigInteger.ZERO) != 0)
        {
            System.out.println(a);
            if (a.compareTo(m) < 0)
            {
                System.out.println("No ghost will come in this year");
                a = in.nextBigInteger();
                if (a.compareTo(BigInteger.ZERO) != 0) System.out.println();
                continue;
            }

            n = a.subtract(m);
            omg = 0;
            /*
              0. The ghost of Tanveer Ahsan – It comes in every 2 year
              1. The ghost of Shahriar Manzoor - It comes in every 5 year
              2. The ghost of Adrian Kugel - It comes in every 7 year
              3. The ghost of Anton Maydell - It comes in every 11 year
              4. The ghost of Derek Kisman - It comes in every 15 year
              5. The ghost of Rezaul Alam Chowdhury - It comes in every 20 year
              6. The ghost of Jimmy Mardell - It comes in every 28 year
              7. The ghost of Monirul Hasan - It comes in every 36 year
              and finally the second most frequent visitor
              8. The ghost of K. M. Iftekhar - It comes in every leap year
            */
            if (n.mod(b) == BigInteger.ZERO)
            {
                omg++;
                System.out.println("Ghost of Tanveer Ahsan!!!");
            }
            if (n.mod(c) == BigInteger.ZERO)
            {
                omg++;
                System.out.println("Ghost of Shahriar Manzoor!!!");
            }
            if (n.mod(d) == BigInteger.ZERO)
            {
                omg++;
                System.out.println("Ghost of Adrian Kugel!!!");
            }
            if (n.mod(e) == BigInteger.ZERO)
            {
                omg++;
                System.out.println("Ghost of Anton Maydell!!!");
            }
            if (n.mod(f) == BigInteger.ZERO)
            {
                omg++;
                System.out.println("Ghost of Derek Kisman!!!");
            }
            if (n.mod(g) == BigInteger.ZERO)
            {
                omg++;
                System.out.println("Ghost of Rezaul Alam Chowdhury!!!");
            }
            if (n.mod(h) == BigInteger.ZERO)
            {
                omg++;
                System.out.println("Ghost of Jimmy Mardell!!!");
            }
            if (n.mod(i) == BigInteger.ZERO)
            {
                omg++;
                System.out.println("Ghost of Monirul Hasan!!!");
            }
            if ((a.mod(j).compareTo(BigInteger.ZERO) == 0 &&
                 a.mod(k).compareTo(BigInteger.ZERO) != 0) ||
                a.mod(l).compareTo(BigInteger.ZERO) == 0)
            {
                omg++;
                System.out.println("Ghost of K. M. Iftekhar!!!");
            }
            if (omg == 0)
                System.out.println("No ghost will come in this year");
            a = in.nextBigInteger();
            if (a.compareTo(BigInteger.ZERO) != 0) System.out.println();
        }
    }
}
