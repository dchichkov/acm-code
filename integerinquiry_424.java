import java.math.*;
import java.util.*;

public class integerinquiry_424
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        BigInteger a = new BigInteger("0");
        BigInteger b = new BigInteger("0");
        while (in.hasNext())
        {
            a = in.nextBigInteger();
            if (a.compareTo(BigInteger.ZERO) == 0) break;
            b = b.add(a);
        }
        System.out.println(b);
    }
}
