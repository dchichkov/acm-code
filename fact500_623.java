import java.util.*;
import java.math.*;

class fact500_623
{
    public static void main(String[] args)
    {
        String n;
        BigInteger a;
        int m;
        Scanner in = new Scanner(System.in);
        while (in.hasNext())
        {
            n = in.nextLine();
            a = new BigInteger(n);
            m = Integer.parseInt(n);
            if (m == 0 || m == 1) a = BigInteger.ONE;
            for (int i = 2; i < m; ++i)
                a = a.multiply(new BigInteger(Integer.toString(i)));
            System.out.println(n + "!");
            System.out.println(a);

        }

    }
}
