import java.util.*;
import java.math.*;

public class factkid_10323
{
    public static void main(String[] args)
    {

        BigInteger a,
            overflow = new BigInteger("6227020800"),
            underflow = new BigInteger("10000");
        String n;
        int m;
        Scanner in = new Scanner(System.in);
        boolean b = true;
        while (in.hasNext())
        {
            n = in.nextLine();
            m = Integer.parseInt(n);
            a = new BigInteger(n);
            b = true;
            if (m == 0 || m == 1) a = BigInteger.ONE;
            for (int i = 2; i < m; ++i)
            {
                a = a.multiply(new BigInteger(Integer.toString(i)));
                if (a.compareTo(overflow) == 1)
                {
                    System.out.println("Overflow!");
                    b = false;
                    break;
                }
            }
            if (b)
            {
                if (a.compareTo(underflow) == -1)
                    System.out.println("Underflow!");
                else 
                    System.out.println(a);
            }
                
        }

    }
}
