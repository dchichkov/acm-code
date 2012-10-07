import java.util.*;
import java.math.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        BigInteger n = new BigInteger("0");
        BigInteger c = new BigInteger("0");
        BigInteger m = new BigInteger("0");
        String op;
        while (in.hasNext())
        {
            n = in.nextBigInteger();
            op = in.next();
            c = in.nextBigInteger();
            System.out.println( ( op.compareTo("%") == 0 ) ? n.mod(c) : n.divide(c) );
        }
    }
}