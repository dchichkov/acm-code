import java.util.*;
import java.math.*;

public class facts_568
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int a, c;
        BigInteger b;
        while (in.hasNext())
        {
            b = new BigInteger("1");
            a = in.nextInt();
            for (Integer i = new Integer(2); i <= a; ++i)
                b = b.multiply(new BigInteger(i.toString()));

            while (b.mod(BigInteger.TEN) == BigInteger.ZERO)
                b = b.divide(BigInteger.TEN);
            System.out.printf("%5d -> %s\n", a, b.mod(BigInteger.TEN).toString());
        }

    }
}
