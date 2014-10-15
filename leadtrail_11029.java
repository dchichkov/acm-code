import java.util.*;
import java.math.*;

public class leadtrail_11029
{
    private static final int EPS = 1000000000;
    
    public static void main(String[] args)
    {
        int tc, b, c;
        long d;
        Scanner in = new Scanner(System.in);
        tc = in.nextInt();
        double a = 0.0;
        while (tc-- > 0)
        {
            a = 0.0;
            d = 1;
            c = in.nextInt();
            b = in.nextInt();
            for (int i = 0; i < b; ++i)
                a += Math.log10(c);
            System.out.print((int)(Math.pow(10, a%1)*100));
            for (int i = 0; i < b; ++i)
            {
                d *= c;
                d %= EPS;
            }
            System.out.print("...");
            System.out.println(d % 1000);

        }
    }
}
