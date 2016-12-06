import java.util.*;
import java.math.*;

public class crisis_11448
{
    public static void main(String[] args)
    {
        BigInteger a, b;
        int tc;
        Scanner in = new Scanner(System.in);
        tc = in.nextInt();
        while (tc-- > 0)
        {
            a = in.nextBigInteger();
            b = in.nextBigInteger();
            System.out.println(a.subtract(b));
        }
    }
}
