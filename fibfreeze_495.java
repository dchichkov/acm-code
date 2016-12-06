import java.util.*;
import java.math.*;

public class fibfreeze_495
{

    public static void main(String[] args)
    {
        int n;
        BigInteger fibs[] = new BigInteger[5005];
        fibs[0] = new BigInteger("0");
        fibs[1] = new BigInteger("1");
        for (int i = 2; i < 5001; ++i)
        {
            fibs[i] = fibs[i-1].add(fibs[i-2]);
        }
        Scanner in = new Scanner(System.in);
        while (in.hasNext())
        {
            n = in.nextInt();
            System.out.printf("The Fibonacci number for %d is %d\n", n, fibs[n]);
        }
    }
}
