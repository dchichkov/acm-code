import java.util.*;
import java.math.*;

public class combos_369
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int n, m;
        int d;
        BigInteger b, c;
        n = in.nextInt();
        m = in.nextInt();
        while (n != 0 && m != 0)
        {
            d = n-m;
            c = new BigInteger("1");
            b = new BigInteger("1");
            for (int i = n; i > d; --i)
                c = c.multiply(new BigInteger(Integer.toString(i)));

            for (int i = m; i > 1; --i)
                b = b.multiply(new BigInteger(Integer.toString(i)));

            System.out.printf("%d things taken %d at a time is %d exactly.\n",
                              n, m, c.divide(b));
            n = in.nextInt();
            m = in.nextInt();
        }
    }
}
