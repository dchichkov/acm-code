import java.util.*;
import java.math.*;

public class bigreal_10464
{
    public static void main(String[] args)
    {
        BigDecimal a, b;
        String c;
        int tc;
        Scanner in = new Scanner(System.in);

        tc = in.nextInt();
        while (tc-- > 0)
        {
            a = in.nextBigDecimal();
            b = in.nextBigDecimal();
            c = a.add(b).toPlainString();
            c = c.replaceAll("[0]*$", "");
            if (c.endsWith("."))
                System.out.println(c + "0");
            else
                System.out.println(c);
        }

    }
}
