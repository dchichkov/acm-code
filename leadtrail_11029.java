import java.util.*;
import java.math.*;

public class leadtrail_11029
{
    public static void main(String[] args)
    {
        int tc, b;
        Scanner in = new Scanner(System.in);
        tc = in.nextInt();
        BigInteger a;
        String one, three;
        while (tc-- > 0)
        {
            one = in.next();
            b = in.nextInt();
            a = new BigInteger(one);

            a = a.pow(b);
            three = a.toString();
            System.out.println(three.substring(0, 3) + "..." +
                               three.substring(three.length()-3, three.length()));

        }
    }
}
