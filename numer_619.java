import java.util.*;
import java.math.*;
import java.text.*;

public class Main
{
    private static DecimalFormat com = new DecimalFormat("#,###");
    public static void main(String[] args)
    {
        BigInteger num, num2;
        BigInteger base = new BigInteger("26");
        Scanner input = new Scanner(System.in);
        String line = new String();
        
        line = input.nextLine();
        while (line.compareTo("*") != 0)
        {
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
                System.out.print(ans.toString());
                System.out.println(com.format(num2).toString());
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
                System.out.print(ans.toString());
                System.out.println(com.format(num).toString());
            }
            
            line = input.nextLine();
        }
    }
}