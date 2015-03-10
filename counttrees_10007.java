import java.util.*;
import java.math.*;

public class counttrees_10007
{

    private static BigInteger catalan[] = new BigInteger[301];
    private static final BigInteger two = new BigInteger("2");

    public static void genCata()
    {
        catalan[0] = BigInteger.ONE;
        BigInteger ibi, jbi = BigInteger.ONE;
        for (int i = 0; i < 300; ++i)
        {
            int top = (((2*i)+1)*((2*i)+2));
            int bottom = (i+2);
            ibi = new BigInteger(Integer.toString(top));
            jbi = new BigInteger(Integer.toString(bottom));
            catalan[i+1] = catalan[i].multiply(ibi);
            catalan[i+1] = catalan[i+1].divide(jbi);
        }
    }
    
    public static void main(String[] args)
    {
        genCata();
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();

        while (n != 0)
        {
            System.out.println(catalan[n]);
            n = input.nextInt();
        }
    }


}