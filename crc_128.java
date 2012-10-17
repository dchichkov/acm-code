import java.math.*;
import java.util.*;

public class crc_128
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        String line;
        BigInteger n;
        
        int p;
        BigInteger wtf = new BigInteger("34943");
        int g = (1<<16)%34943;
        while (in.hasNext())
        {
            line = in.nextLine();
            if (line.compareTo("#") == 0 || line.indexOf("#") != -1) break;
            if (line.length() == 0)
            {
                System.out.printf("00 00\n");
            }
            else
            {
                n = (new BigInteger(line.getBytes())).mod(wtf);
                p = (34943 - ((n).intValue() * g % 34943));
                System.out.printf("%02X %02X\n", p>>8 , p%256);            
            }
        }
    }
}
/* (a*b)%c == (a%c * b%c)%c
 *
 * uhhh which ... doesn't apply?
 * 2^16 % 34943
 * 34943 - (line.getBytes() % 34943) * 2^16 % 34943 */