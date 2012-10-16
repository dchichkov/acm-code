import java.math.*;
import java.util.*;

public class crc_128
{
    private static final String g = "34943";
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        String line = new String();
        BigInteger n;
        int p;
        while (in.hasNext())
        {
            line = in.nextLine();
            if (line.compareTo("#") == 0) break;
            if (line.length() == 0)
            {
                System.out.printf("00 00\n");
            }
            else
            {
                n = (new BigInteger(line.getBytes())).shiftLeft(16);
                p = (34943 - (n.mod(new BigInteger(g))).intValue())%34943;
                System.out.printf("%02X %02X\n", p>>8 , p%256);            
            }
        }
    }
}