/*
 * exhaustively test isaac's program vs my program
 */

import java.io.*;
import java.lang.*;
import java.math.*;

public class test_619
{
    private static FileInputStream a, b;
    private static FileOutputStream c, f;
    private static BigInteger d, macks;
    
    public static void doTest() throws Exception, FileNotFoundException
    {
        Runtime run = Runtime.getRuntime();
        
        //test
        f = new FileOutputStream("619test_num.txt", false);
        f.write(new String(d.toString() + "\n*").getBytes());

        String cmdi = "./619.exe < 619test_num.txt > 619_isaac";

        Process pr1 = run.exec(cmdi);
        pr1.waitFor();

        String[] num = new String[1];
        num[0] = d.toString();
        numer_619.main(num);
        
        //check result
        byte[] answer = new byte[1000];
        a = new FileInputStream("619_isaac");
        a.read(answer);
        String isaac_ans = new String(answer);
        
        b = new FileInputStream("619_matt");
        b.read(answer);
        String matt_ans = new String(answer);
        
        System.out.println(isaac_ans);
        if (isaac_ans.compareTo(matt_ans) != 0)
        {
            c.write(new String(isaac_ans + " != " + matt_ans + "\n").getBytes());
        }
            
    }
    
    public static void main(String[] args)
    {
        d = new BigInteger("1");
        macks = new BigInteger("20725274851017785518433805271");

        try
        {
            c = new FileOutputStream("619_diff", true);
        }
        catch (Exception e)
        {
            System.out.println(e.getMessage());
        }
            
        while (d.compareTo(macks) != 0)
        {
            try
            {
                doTest();
            }
            catch (Exception e)
            {}
            
            d = d.add(BigInteger.ONE);
        }
    }
}
