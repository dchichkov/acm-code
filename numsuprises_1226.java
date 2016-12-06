import java.util.*;
import java.math.*;

public class numsuprises_1226
{
    public static void main(String[] args)
    {
        int tc;
        BigInteger a, b;
        Scanner in = new Scanner(System.in);
        tc = in.nextInt();

        while (tc-- > 0)
        {
            a = in.nextBigInteger();
            b = in.nextBigInteger();
            System.out.println(b.mod(a));
        }
    }

}
