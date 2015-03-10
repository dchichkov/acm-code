import java.util.*;

public class funnymethod_10019
{
    public static void main(String[] args)
    {
        int tc;
        Scanner in = new Scanner(System.in);
        String num, a, b;
        tc = in.nextInt();
        while (tc-- > 0)
        {
            num = in.next();
            a = Integer.toBinaryString(Integer.parseInt(num, 10));
            b = Integer.toBinaryString(Integer.parseInt(num, 16));
            System.out.println((a.length() - a.replace("1", "").length()) + " " +
                               (b.length() - b.replace("1", "").length()));
        }
    }
}
