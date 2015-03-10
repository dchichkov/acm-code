import java.util.*;
import java.math.*;

public class highprecnum_11821
{
    public static void main(String[] args)
    {
        BigDecimal a;
        String b;
        int tc;
        Scanner in = new Scanner(System.in);

        tc = Integer.parseInt(in.nextLine());
        while (tc-- > 0)
        {
            a = new BigDecimal("0");
            b = in.nextLine();
            while (b.compareTo("0") != 0)
            {
                a = a.add(new BigDecimal(b));
                b = in.nextLine();
            }
            a = a.stripTrailingZeros();
            //if (a.remainder(BigDecimal.ONE).compareTo(BigDecimal.ZERO) == 0)
            //    System.out.println(a.toBigIntegerExact());
            //else
            System.out.println(a.toPlainString());
        }

    }
}
