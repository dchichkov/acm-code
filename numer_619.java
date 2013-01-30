import java.util.*;
import java.math.*;
import java.text.*;
import java.io.*;

public class numer_619
{
    private static DecimalFormat com = new DecimalFormat("#,###");
    private static FileOutputStream a;
    public static void main(String[] args)
    {
        try
        {
        BigInteger num, num2;
        BigInteger base = new BigInteger("26");
        a = new FileOutputStream("619_matt", true);
        String line = args[0];

        if (Character.isDigit(line.charAt(0)))
        {
            //get the string answer
            StringBuilder ans = new StringBuilder();
            num = new BigInteger(line);
            num2 = new BigInteger(line);
            while (num.compareTo(BigInteger.ZERO) != 0)
            {
                ans.insert(0, (char)((num.mod(base).intValue()+0x60)));
                num = num.divide(base);
            }
            for (int i = ans.length()+1; i < 23; ++i)
                ans.append(" ");
            a.write(ans.toString().getBytes());
            a.write(com.format(num2).toString().getBytes());
        }
        else
        {
            //get the number value
            num = new BigInteger("0");
            StringBuilder ans = new StringBuilder(line);
            for (int i = line.length()-1, exp = 0; i >= 0; --i, ++exp)
            {
                BigInteger h = new BigInteger(Integer.toString(((int)(line.charAt(i))-0x60)));
                num = num.add(h.multiply(base.pow(exp)));
            }
            for (int i = ans.length()+1; i < 23; ++i)
                ans.append(" ");
            a.write(ans.toString().getBytes());
            a.write(com.format(num).toString().getBytes());
        }
        }
        catch (Exception e) { System.out.println(e.getMessage()); }
            
    }
}
