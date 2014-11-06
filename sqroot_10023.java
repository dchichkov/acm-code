import java.math.*;
import java.util.*;

public class sqroot_10023
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int tc;
        BigInteger a, b, two = new BigInteger("2");
        tc = in.nextInt();
        String str;
        while (tc-- > 0)
        {
            a = in.nextBigInteger();
            str = a.toString();
            b = new BigInteger(str.substring(0, (str.length()/2)+1));
            //System.out.println(b);
            while (a.divide(b).compareTo(b) == -1)
            {
                b = b.add(a.divide(b)).divide(two);
                //System.out.println(b);
            }
            System.out.println(b);
            if (tc != 0) System.out.println();
        }
    }
}
