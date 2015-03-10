import java.util.*;

public class ternary_11185
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        while (n >= 0)
        {
            System.out.println(Integer.toString(n, 3));
            n = in.nextInt();
        }
    }
}
