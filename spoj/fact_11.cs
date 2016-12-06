using System;
using System.IO;

public class fact_11
{
    const int LIMIT = 1000000000;
    public static void Main()
    {
        int tc;
        string[] tokens;
        tokens = Console.ReadLine().Split();
        tc = int.Parse(tokens[0]);
        int a, b;
        int d;
        while (tc-- > 0)
        {
            d = 0;
            tokens = Console.ReadLine().Split();
            a = int.Parse(tokens[0]);
            b = a;
            for (int i = 5; i <= a && i > 0; i *= 5)
                d += b/i;
            Console.WriteLine("{0}", d);
        }
    }

}