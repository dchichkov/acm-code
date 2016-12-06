import java.util.*;
import java.math.*;

class exponentiation_748
{
    public static void main(String[] args)
    {
        BigDecimal a;
        int n;
        Scanner in = new Scanner(System.in);
        String num;
        StringBuilder omg;
        while (in.hasNext())
        {
            num = in.next();
            a = new BigDecimal(num);
            n = in.nextInt();
            omg = new StringBuilder(a.pow(n).toPlainString().toString());
            while (omg.substring(0, 1).compareTo("0") == 0) omg = omg.deleteCharAt(0);
            omg = omg.reverse();
            while (omg.substring(0, 1).compareTo("0") == 0) omg = omg.deleteCharAt(0);
            System.out.println(omg.reverse().toString());

        }
    }
}
