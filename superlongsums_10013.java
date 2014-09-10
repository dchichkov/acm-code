import java.util.*;
import java.math.*;

public class superlongsums_10013
{

    public static void main(String[] args)
    {
        int tc, nc;
        BigInteger c = new BigInteger("0");
        Scanner in = new Scanner(System.in);
        tc = in.nextInt();
        while (tc-- > 0)
        {
            c = BigInteger.ZERO;
            nc = in.nextInt();
            for (int i = 0; i < nc; ++i)
            {
                c = c.add(new BigInteger(new Integer((int)(in.next().charAt(0)-0x30)*(int)Math.pow(10, nc-i-1)).toString()));
                c = c.add(new BigInteger(new Integer((int)(in.next().charAt(0)-0x30)*(int)Math.pow(10, nc-i-1)).toString()));
            }

            System.out.println(c);
            if (tc != 0)
                System.out.println();
        }
    }

}
