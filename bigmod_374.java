import java.util.*;
import java.math.*;

public class bigmod_374
{
    public static void main(String[] args)
    {
        BigInteger a, b, c;
        Scanner in = new Scanner(System.in);
        while (in.hasNext())
        {
            a = in.nextBigInteger();
            b = in.nextBigInteger();
            c = in.nextBigInteger();
            System.out.println(a.modPow(b, c));
        }
    }
}
