import java.util.*;
import java.math.*;

public class division_10083
{
    public static void main(String[] args)
    {
        BigInteger r, s, t;
        BigInteger[] u;
        int a, b;
        Scanner in = new Scanner(System.in);
        while (in.hasNext())
        {
            t = in.nextBigInteger();
            a = in.nextInt();
            b = in.nextInt();

            r = t.pow(a).subtract(BigInteger.ONE);
            s = t.pow(b).subtract(BigInteger.ONE);
            u = r.divideAndRemainder(s);

            System.out.print("(" + t + "^" + a + "-1)/(" + t + "^" + b + "-1) ");
            if (u[0].toString().length() < 100 && u[1].compareTo(BigInteger.ZERO) == 0)
                System.out.println(u[0]);
            else
                System.out.println("is not an integer with less than 100 digits.");

        }
    }
}
