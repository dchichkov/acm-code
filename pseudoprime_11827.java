import java.math.*;
import java.util.*;

public class pseudoprime_11827
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        BigInteger p, a;

        p = in.nextBigInteger();
        a = in.nextBigInteger();
        while (p.compareTo(BigInteger.ZERO) != 0 && a.compareTo(BigInteger.ZERO) != 0)
        {
            if (!p.isProbablePrime(10) && a.modPow(p, p).compareTo(a) == 0)
                System.out.println("yes");
            else
                System.out.println("no");

            p = in.nextBigInteger();
            a = in.nextBigInteger();
        }
    }
}
