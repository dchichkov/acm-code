import java.util.*;
import java.math.*;

public class remains_10551
{
    public static void main(String[] args)
    {
        int b;
        String a, c;
        BigInteger d, e;
        Scanner in = new Scanner(System.in);
        b = in.nextInt();
        while (b != 0)
        {
            a = in.next();
            c = in.next();
            d = new BigInteger(a, b);
            e = new BigInteger(c, b);
            System.out.println(d.mod(e).toString(b));
            b = in.nextInt();
        }

    }

}
