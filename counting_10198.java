import java.util.*;
import java.math.*;

public class counting_10198
{
    public static int count(String num)
    {
        int ttl = 0;
        for (char x : num.toCharArray())
            if (x == '4')
                ttl += 1;
            else
                ttl += x-0x30;

        return ttl;
    }
        
    
    public static void main(String[] args)
    {
        int n;
        Scanner in = new Scanner(System.in);
        char[] chars;
        String s;
        BigInteger a;
        int ttl = 0;
        while (in.hasNextInt())
        {
            n = in.nextInt();
            ttl = 0;
            chars = new char[n];
            Arrays.fill(chars, '4');
            s = new String(chars);
            a = new BigInteger(s);
            while (a.compareTo(BigInteger.ZERO) == 1)
            {
                if (count(a.toString()) == n)
                    ttl++;

                //subtract 1
                a = a.subtract(BigInteger.ONE);
                while (a.toString().contains("0")) a = a.subtract(BigInteger.ONE);
                a = new BigInteger(a.toString().replaceAll("[5-9]", "4"));
            }
            System.out.println(ttl);
        }
    }
}
