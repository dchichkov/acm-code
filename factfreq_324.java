import java.util.*;
import java.math.*;

public class factfreq_324
{
    public static void main(String[] args)
    {
        BigInteger a;
        int m;
        Scanner in = new Scanner(System.in);
        m = in.nextInt();
        int zero,
            one,
            two,
            three,
            four,
            five,
            six,
            seven,
            eight,
            nine;
            
        while (m != 0)
        {
            a = new BigInteger(Integer.toString(m));
            if (m == 0 || m == 1) a = BigInteger.ONE;
            for (int i = 2; i < m; ++i)
                a = a.multiply(new BigInteger(Integer.toString(i)));
            System.out.println(m + "! --");

            zero = a.toString().length() - a.toString().replace("0", "").length();
            one = a.toString().length() - a.toString().replace("1", "").length();
            two = a.toString().length() - a.toString().replace("2", "").length();
            three = a.toString().length() - a.toString().replace("3", "").length();
            four = a.toString().length() - a.toString().replace("4", "").length();
            five = a.toString().length() - a.toString().replace("5", "").length();
            six = a.toString().length() - a.toString().replace("6", "").length();
            seven = a.toString().length() - a.toString().replace("7", "").length();
            eight = a.toString().length() - a.toString().replace("8", "").length();
            nine = a.toString().length() - a.toString().replace("9", "").length();
            
            System.out.printf("   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%5d\n",
                              zero, one, two, three, four);
            System.out.printf("   (5)%5d    (6)%5d    (7)%5d    (8)%5d    (9)%5d\n",
                              five, six, seven, eight, nine);
            
            m = in.nextInt();
        }

    }
}
