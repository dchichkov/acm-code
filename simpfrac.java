
import java.util.*;
import java.math.*;

public class Main//simpfrac
{
    /*public static BigInteger gcd(BigInteger a, BigInteger b)
    {
        return (b!=0) ? gcd(b, a.mod(b)) : a;
        }*/
       
    public static void main(String[] args)
    {
        BigInteger a = new BigInteger("0");
        BigInteger b = new BigInteger("0");
        Scanner in = new Scanner(System.in);
        int num_cases = in.nextInt();
        while (num_cases-- > 0)
        {
            a = in.nextBigInteger();
            in.next();
             
            b = in.nextBigInteger();

            //System.out.printf("%d / %d\n", a, b);
            BigInteger div = a.gcd(b);
            
            System.out.printf("%d / %d\n", a.divide(div), b.divide(div));
        }

    }
}