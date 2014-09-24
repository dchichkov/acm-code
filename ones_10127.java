import java.util.*;
import java.math.*;

public class ones_10127
{
    public static void main(String[] args)
    {

        BigInteger a = new BigInteger("0"), b;
        Scanner in = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        while (in.hasNext())
        {
            b = in.nextBigInteger();
            a = a.add(b);
            for (int i = 0; i < a.toString().length(); ++i)
                sb.append("1");
            while (a.toString().compareTo(sb.toString()) != 0)
            {
                a = a.add(b);
                for (int i = sb.toString().length(); i < a.toString().length(); ++i)
                    sb.append("1");
            }
            System.out.println(a.toString().length());
            sb.delete(0, sb.toString().length());
        }
    }

}
