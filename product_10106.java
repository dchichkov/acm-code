import java.util.*;
import java.math.*;

public class product_10106
{

    public static void main(String[] args)
    {
        BigInteger a, b;
        Scanner in = new Scanner(System.in);
        while (in.hasNext())
        {
            a = in.nextBigInteger();
            b = in.nextBigInteger();
            System.out.println(a.multiply(b));
        }
    }
}
