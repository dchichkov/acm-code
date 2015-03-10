import java.util.*;
import java.math.*;

public class bignums_10220
{
    public static void main(String[] args)
    {
        String n;
        BigInteger a;
        int m, ttl;
        Scanner in = new Scanner(System.in);
        while (in.hasNext())
        {
            m = in.nextInt();
            ttl = 0;
            a = new BigInteger(Integer.toString(m));
            if (m == 0 || m == 1) a = BigInteger.ONE;
            for (int i = 2; i < m; ++i)
                a = a.multiply(new BigInteger(Integer.toString(i)));

            n = a.toString();
            for (int i = 0; i < n.length(); ++i)
                ttl += n.toCharArray()[i]-0x30;

            System.out.println(ttl);
        }

    }
}
