import java.util.*;

public class basicspeak_389
{
    public static void main(String[] args)
    {
        String a, d;
        int b, c;
        Scanner in = new Scanner(System.in);
        while (in.hasNext())
        {
            a = in.next();
            b = in.nextInt();
            c = in.nextInt();
            try
            {
                d = Integer.toString(Integer.valueOf(a, b), c);
                System.out.printf("%7s\n", d.length() > 7 ? "ERROR" : d.toUpperCase());
            }
            catch (Exception e)
            {
                System.out.printf("%7s\n", "ERROR");
            }
        }

    }
}
