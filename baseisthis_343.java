import java.util.*;
import java.math.*;

public class baseisthis_343
{
    public static void main(String[] args)
    {
        String a,b;
        Scanner in = new Scanner(System.in);
        while (in.hasNext())
        {
            a = in.next();
            b = in.next();
            int i = 0, j = 0;
            boolean m = false;
            for (i = 2; i < 37; ++i)
            {
                m = false;
                for (j = 2; j < 37; ++j)
                {
                    if (new BigInteger(a).toString(i).compareTo(new BigInteger(b).toString(j)) == 0)
                        m = true;
                    if (m) break;
                }
                if (m) break;
            }
            if (!m)
                System.out.printf("%s is not equal to %s in any base 2..36", a, b);
            else
                System.out.printf("%s (base %d) = %s (base %d)", a, i, b, j);
            System.out.println();
        }
    }
}
