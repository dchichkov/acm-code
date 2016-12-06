import java.util.*;

public class pascal_325
{
    public static void main(String[] args)
    {
        String s;
        Scanner in = new Scanner(System.in);
        s = in.nextLine();
        while (s.compareTo("*") != 0)
        {
            s = s.trim();
            System.out.printf("%s is ", s);
            if (s.matches("[-+]?\\d+(\\.\\d+([eE][-+]?\\d+)?|[eE][-+]?\\d+)"))
                System.out.println("legal.");
            else
                System.out.println("illegal.");
            
            s = in.nextLine();
        }
    }
}
