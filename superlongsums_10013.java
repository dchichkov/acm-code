import java.util.*;
import java.math.*;

public class superlongsums_10013
{

    public static void main(String[] args)
    {
        int tc, nc;
        BigInteger c, d;
        Scanner in = new Scanner(System.in);
        StringBuilder a = new StringBuilder();
        StringBuilder b = new StringBuilder();
        tc = in.nextInt();
        while (tc-- > 0)
        {
            nc = in.nextInt();
            for (int i = 0; i < nc; ++i)
            {
                a.append(in.next());
                b.append(in.next());
            }
            c = new BigInteger(a.toString());
            d = new BigInteger(b.toString());
            a.delete(0, a.length());
            b.delete(0, b.length());
            System.out.println(c.add(d));
            if (tc != 0)
                System.out.println();
        }
    }

}
