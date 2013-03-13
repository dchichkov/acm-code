import java.util.*;

public class time_518
{

    private static GregorianCalendar a = new GregorianCalendar();
    private static GregorianCalendar b = new GregorianCalendar();
    
    public static void main(String[] args)
    {

        Scanner input = new Scanner(System.in);
        String s;
        long c, d;
        long division = 1, t;
        long ans = 0, wat = 0;
        int ny;
        long seconds = 0;
        while (input.hasNext() && ++wat < 5)
        {
            //wat = 0;
            seconds = 0;
            a.set(input.nextInt(), input.nextInt()-1, input.nextInt(),
                  input.nextInt(), input.nextInt(), input.nextInt());
            /*
            ny = input.nextInt();

            for (int i = 1; i <= (ny-a.get(Calendar.YEAR)); ++i)
            {
                b.set(a.get(Calendar.YEAR)+i, 0, 1, 0, 0, 0);
                wat += b.getTimeInMillis() - a.getTimeInMillis();
                System.out.println(wat);
                a.set(Calendar.YEAR, a.get(Calendar.YEAR)+1);
            }
*/
            b.set(input.nextInt(), input.nextInt()-1, input.nextInt(),
                  input.nextInt(), input.nextInt(), input.nextInt());


            //System.out.println(b.getTimeInMillis() - a.getTimeInMillis());
            t = input.nextLong();
            s = input.next();
            /*

            c = a.getTimeInMillis();
            d = b.getTimeInMillis();
            */
            
            diff.clear();
            diff.add(Calendar.YEAR, (b.get(Calendar.YEAR)-a.get(Calendar.YEAR)));
            //diff.add(Calendar.MONTH, (b.get(Calendar.MONTH)-a.get(Calendar.MONTH)));
            diff.add(Calendar.DAY_OF_YEAR, (b.get(Calendar.DAY_OF_YEAR)-a.get(Calendar.DAY_OF_YEAR)));
            diff.add(Calendar.HOUR, (b.get(Calendar.HOUR)-a.get(Calendar.HOUR)));
            diff.add(Calendar.MINUTE, (b.get(Calendar.MINUTE)-a.get(Calendar.MINUTE)));
            diff.add(Calendar.SECOND, (b.get(Calendar.SECOND)-a.get(Calendar.SECOND)));

            a.add(Calendar.YEAR, diff.get(Calendar.YEAR)-1970);
            a.add(Calendar.DAY_OF_MONTH, diff.get(Calendar.DAY_OF_MONTH));
            a.add(Calendar.HOUR, diff.get(Calendar.HOUR));
            a.add(Calendar.MINUTE, diff.get(Calendar.MINUTE));
            a.add(Calendar.SECOND, diff.get(Calendar.SECOND));
            
            System.out.println("diff: " + diff);
            System.out.println("diff time: " + diff.getTimeInMillis());
            System.out.println(a.compareTo(b));
            System.out.println("a :" + a);
            System.out.println("b :" + b);

            if (s.compareTo("second") == 0)
            {
                ans = (diff.get(Calendar.SECOND) +
                       diff.get(Calendar.MINUTE-1)*60 +
                       diff.get(Calendar.HOUR-1)*60*60 +
                       (diff.get(Calendar.DAY_OF_YEAR)-1)*60*60*24 +
                       (diff.get(Calendar.YEAR)-1970)*60*60*24*365) / t;
            }
            else if (s.compareTo("minute") == 0)
            {
                ans = (diff.get(Calendar.MINUTE) +
                       (diff.get(Calendar.HOUR)-1)*60 +
                       (diff.get(Calendar.DAY_OF_YEAR)-1)*60*24 +
                       (diff.get(Calendar.YEAR)-1970)*60*24*365) / t;
            }
            else if (s.compareTo("hour") == 0)
            {
                ans = (diff.get(Calendar.HOUR) +
                       (diff.get(Calendar.DAY_OF_YEAR)-1)*24 +
                       (diff.get(Calendar.YEAR)-1970)*24*365) / t;
            }
            else if (s.compareTo("day") == 0)
            {
                ans = ((diff.get(Calendar.DAY_OF_YEAR)-1) +
                       (diff.get(Calendar.YEAR)-1970)*365) / t;
            }
            else if (s.compareTo("month") == 0)
            {
                ans = (diff.get(Calendar.MONTH) +
                       (diff.get(Calendar.YEAR)-1970)*12) / t;
            }
            else if (s.compareTo("year") == 0)
            {
                ans = ((diff.get(Calendar.YEAR)-1970)) / t;
            }

         /* System.out.println("a: " + a.toString());
            System.out.println("b: " + b.toString());
            System.out.println("d: " + d);
            System.out.println("c: " + c);
            System.out.println("t: " + t);
            System.out.println("division: " + division);
            System.out.println("d-c: " + (d-c));
            System.out.println("t*division: " + (t*division)); */
            //System.out.printf("%d\n", (long)((d-c)/(t * division)));
            System.out.printf("%d\n", ans);
                

        }

    }


}