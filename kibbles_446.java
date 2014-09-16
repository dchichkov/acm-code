import java.util.*;

public class kibbles_446
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int tc;
        tc = in.nextInt();
        int a,b,c;
        String op;
        while (tc-- > 0)
        {
            a = Integer.valueOf(in.next(), 16);
            op = in.next();
            b = Integer.valueOf(in.next(), 16);
            c = 0;
            switch(op)
            {
            case "+":
                c = a+b;
                break;
            case "-":
                c = a-b;
            }
            System.out.printf("%s %s %s = %d\n",
                              String.format("%13s", Integer.toString(a, 2)).replace(' ', '0'),
                              op,
                              String.format("%13s", Integer.toString(b, 2)).replace(' ', '0'),
                              c);
        }
    }
}
