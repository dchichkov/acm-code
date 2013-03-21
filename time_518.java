import java.util.*;

public class time_518
{

    private static GregorianCalendar a = new GregorianCalendar();
    private static GregorianCalendar b = new GregorianCalendar();
    
    public static void main(String[] args)
    {

        Scanner input = new Scanner(System.in);
        String s;
        long t;
        long ans = 0;
        int ny;
        while (input.hasNextInt())
        {
            a.set(input.nextInt(), input.nextInt()-1, input.nextInt(),
                  input.nextInt(), input.nextInt(), input.nextInt());
            b.set(input.nextInt(), input.nextInt()-1, input.nextInt(),
                  input.nextInt(), input.nextInt(), input.nextInt());
            t = input.nextLong();
            s = input.next();

            int y, mo, moo, da, h, mi, se;
            y = mo = da = h = mi = se = moo= 0;
            
            if (a.isLeapYear(a.get(Calendar.YEAR)) &&
                b.get(Calendar.MONTH) > 2 && a.get(Calendar.MONTH) <= 2 &&
                a.get(Calendar.DAY_OF_MONTH) < 28)
            {
                da++;
            }
            moo = a.get(Calendar.MONTH);
            while (a.get(Calendar.SECOND) != b.get(Calendar.SECOND))
            {
                a.add(Calendar.SECOND, 1);
                se++;
            }
            while (a.get(Calendar.MINUTE) != b.get(Calendar.MINUTE))
            {
                a.add(Calendar.MINUTE, 1);
                mi++;
            }
            while (a.get(Calendar.HOUR) != b.get(Calendar.HOUR))
            {
                a.add(Calendar.HOUR, 1);
                h++;
            }
            while (a.get(Calendar.YEAR) != b.get(Calendar.YEAR))
            {
                a.add(Calendar.YEAR, 1);
                y++;
                if (a.isLeapYear(a.get(Calendar.YEAR))) da++;
            }
            while (a.get(Calendar.DAY_OF_YEAR) != b.get(Calendar.DAY_OF_YEAR))
            {
                if (a.get(Calendar.DAY_OF_YEAR) < b.get(Calendar.DAY_OF_YEAR))
                {
                    a.add(Calendar.DAY_OF_YEAR, 1);
                    da++;
                }
                else if (a.get(Calendar.DAY_OF_YEAR) > b.get(Calendar.DAY_OF_YEAR))
                {
                    a.add(Calendar.DAY_OF_YEAR, -1);
                    da--;
                }
                if (a.get(Calendar.MONTH) != moo)
                {
                    mo++;
                    moo = a.get(Calendar.MONTH);
                }
            }
            while (a.get(Calendar.HOUR_OF_DAY) != b.get(Calendar.HOUR_OF_DAY))
            {
                if (a.get(Calendar.HOUR_OF_DAY) < b.get(Calendar.HOUR_OF_DAY))
                {
                    a.add(Calendar.HOUR_OF_DAY, 1);
                    h++;
                }
                else if (a.get(Calendar.HOUR_OF_DAY) > b.get(Calendar.HOUR_OF_DAY))
                {
                    a.add(Calendar.HOUR_OF_DAY, -1);
                    h--;
                }
            }

            if (a.compareTo(b) != 0)
            {
                System.out.println(a);
                System.out.println(b); }

            if (s.compareTo("second") == 0)
            {
                ans = ((y*365*24*60*60) +
                       (da * 24 * 60 * 60) +
                       (h * 60 * 60) +
                       (mi * 60) +
                       (se));
            }
            else if (s.compareTo("minute") == 0)
            {
                ans = ((y*365*24*60) +
                       (da * 24 * 60) +
                       (h * 60) +
                       (mi));
            }
            else if (s.compareTo("hour") == 0)
            {
                ans = ((y*365*24) +
                       (da * 24) +
                       (h));
            }
            else if (s.compareTo("day") == 0)
            {
                ans = ((y*365) +
                       (da));
            }
            else if (s.compareTo("month") == 0)
            {
                ans = ((y*12) +
                       mo);
            }
            else if (s.compareTo("year") == 0)
            {
                ans = y;
            }

            System.out.printf("%d\n", ans / t);
                
        }
    }
}