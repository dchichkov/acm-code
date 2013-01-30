import java.text.*;
import java.math.*;
import java.util.*;

public class howold_11219
{

    public static void main(String[] args) throws ParseException, Exception
    {
        SimpleDateFormat format = new SimpleDateFormat("dd/MM/yyyy");

        long years;
        Date d1, d2;
        int nc, c = 0;
        GregorianCalendar g1, g2;
        BigDecimal a, b;
        Scanner input = new Scanner(System.in);
        nc = input.nextInt();
        input.nextLine(); //grab rest of line
        input.nextLine(); //grab empty line
        while (nc-- > 0)
        {
            c++;
            try {
                String l1, l2;
                l1 = input.nextLine();
                l2 = input.nextLine();
                //System.out.println("l1: " + l1 + "\nl2: " + l2);
                
                d1 = format.parse(l1);
                d2 = format.parse(l2);
                g1 = new GregorianCalendar();
                g2 = new GregorianCalendar();
                g1.set(d1.getYear(), d1.getMonth(), d1.getDay(), 0, 0, 0);
                g2.set(d2.getYear(), d2.getMonth(), d2.getDay(), 0, 0, 0);
                a = new BigDecimal((1000*60*60*24*365.25));
                b = new BigDecimal((d1.getTime() - d2.getTime()));
                years = ((b.divideToIntegralValue(a)).longValue());
                System.out.println("d1: " + d1);
                System.out.println("d2: " + d2);
                System.out.println("g1: " + g1.getTime().toString());
                System.out.println("g2: " + g2.getTime().toString());
                System.out.println("years: " + years);
                System.out.print("Case #" + c + ": ");

                if (g2.compareTo(g1) == 1)
                {
                    System.out.println("Invalid birth date");
                }
                else
                {
                    
                    if (years > 130)
                    {
                        System.out.println("Check birth date");
                    }
                    else
                    {
                        System.out.println(years);
                    }
                }
            }
            catch (Exception e) { throw(e); }

            try
            {
            input.nextLine();
            }
            catch (Exception e) { /* dunno if last line in input file exists or not*/ };
        }

    }
}
