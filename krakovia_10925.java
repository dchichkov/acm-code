import java.util.*;
import java.math.*;

public class krakovia_10925
{
    public static void main(String[] args)
    {
        int ni, nf, cnt = 0;
        Scanner in = new Scanner(System.in);
        ni = in.nextInt();
        nf = in.nextInt();
        BigInteger a = new BigInteger("0"), b;
        while (ni != 0 && nf != 0)
        {
            for (int i = 0; i < ni; ++i)
            {
                b = in.nextBigInteger();
                a = a.add(b);
            }
            System.out.printf("Bill #%d costs %d: each friend should pay %d\n", ++cnt,
                              a, a.divide(new BigInteger(new Integer(nf).toString())));
            
            ni = in.nextInt();
            nf = in.nextInt();
            a = new BigInteger("0");
            System.out.println();
        }
    }

}
