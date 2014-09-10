import java.util.*;
import java.util.Scanner;
import java.math.*;

class overflow_465
{
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in);
        BigInteger a, b, x, c = BigInteger.ZERO;
        c = c.add(BigInteger.valueOf(Integer.MAX_VALUE));
        String op = new String();
        String line = new String();
        boolean ip;
        int omg;
        while (in.hasNext())
        {
            ip = false;
            line = in.nextLine();
            x = new BigInteger("0");
            if (line.indexOf("+") != -1)
                ip = true;
            omg = line.indexOf(ip ? "+" : "*");
            a = new BigInteger(line.substring(0, line.indexOf(" ") == -1 ?
                                              omg : line.indexOf(" ")));
            
            if (ip)
                op = "+";
            else
                op = "*";

            b = new BigInteger(line.substring(line.lastIndexOf(" ") == -1 ?
                                              omg+1 : line.lastIndexOf(" ")+1, line.length()));

            switch (op)
            {
            case "+":
                x = a.add(b);
                break;
            case "*":
                x = a.multiply(b);
                break;
            }
            System.out.printf("%s%s%s\n", line.substring(0, line.indexOf(" ") == -1 ?
                                                         omg : line.indexOf(" ")),
                              (line.indexOf(" ") == -1 ? op : line.substring(line.indexOf(" "),
                                                                          (line.lastIndexOf(" ") == -1 ? omg : line.lastIndexOf(" ")))), line.substring(line.lastIndexOf(" ") == -1 ?
                                             omg+1 : line.lastIndexOf(" "), line.length()));
            if (a.compareTo(c) > 0)
                System.out.printf("first number too big\n");
            if (b.compareTo(c) > 0)
                System.out.printf("second number too big\n");
            if (x.compareTo(c) > 0)
                System.out.printf("result too big\n");
                
        }


    }
}
