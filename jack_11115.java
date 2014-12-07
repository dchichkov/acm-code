import java.util.*;
import java.math.*;

public class jack_11115
{
    public static void main(String[] args)
    {
        BigInteger a;
        int b;
        Scanner in = new Scanner(System.in);
        a = in.nextBigInteger();
        b = in.nextInt();
        while (a.compareTo(BigInteger.ZERO) != 0)
        {
            System.out.println(a.pow(b));
            a = in.nextBigInteger();
            b = in.nextInt();
        }
    }
}
