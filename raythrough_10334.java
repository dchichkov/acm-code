import java.util.*;
import java.math.*;

public class raythrough_10334
{
    public static void main(String[] args)
    {
        BigInteger fibs[] = new BigInteger[1005];
        fibs[0] = new BigInteger("1");
        fibs[1] = new BigInteger("2");

        for (int i = 2; i < 1005; ++i)
        {
            fibs[i] = fibs[i-1].add(fibs[i-2]);
        }
        
        int n;
        Scanner in = new Scanner(System.in);
        while (in.hasNext())
        {
            n = in.nextInt();
            System.out.println(fibs[n]);
        }
    }

}
