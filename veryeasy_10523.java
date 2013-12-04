import java.util.*;
import java.math.BigInteger;

class veryeasy_10523
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int n;
        BigInteger A = new BigInteger("0");

        String j;
        while (input.hasNextInt())
        {
            BigInteger B = new BigInteger("0");
            n = input.nextInt();
            A = input.nextBigInteger();
            //System.out.println("n: " + n + " A:" + A);
            for (int i = 1; i <= n; ++i)
            {
                j = Integer.toString(i);
                B = B.add(A.pow(i).multiply(new BigInteger(j)));
            }
            System.out.println(B);
        }

    }
}
