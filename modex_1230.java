import java.util.*;
import java.math.*;

public class modex_1230
{
    public static void main(String[] args)
    {
        BigInteger a, b, c;
        int tc;
        Scanner in = new Scanner(System.in);

        tc = in.nextInt();
        while (tc-- > 0)
        {
            a = in.nextBigInteger();
            b = in.nextBigInteger();
            c = in.nextBigInteger();

            System.out.println(a.modPow(b,c));
        }

    }
}
