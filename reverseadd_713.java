import java.util.*;
import java.math.*;

class reverseadd_713
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int tc;
        tc = in.nextInt();
        BigInteger a, b;
        StringBuilder c, d;
        while (tc-- > 0)
        {
            c = new StringBuilder(in.next());
            d = new StringBuilder(in.next());
            a = new BigInteger(c.reverse().toString());
            b = new BigInteger(d.reverse().toString());
            a = a.add(b);
            System.out.println(new BigInteger(new StringBuilder(a.toString()).reverse().toString()));

        }
    }
}
