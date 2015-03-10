import java.util.*;
import java.math.*;

public class multof17_11879
{
    public static void main(String[] args)
    {
        BigInteger a, b = new BigInteger("17");
        Scanner in = new Scanner(System.in);
        a = in.nextBigInteger();
        while (a.compareTo(BigInteger.ZERO) != 0)
        {
            if (a.mod(b) == BigInteger.ZERO)
                System.out.println(1);
            else
                System.out.println(0);

            a = in.nextBigInteger();
        }

    }

}
