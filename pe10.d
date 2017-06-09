import std.stdio;
import std.bigint;

void main()
{
    BigInt num = BigInt();
    int num_divs = 0, growing_divs = 0;
    for (BigInt i = BigInt("10"), n, high; ; ++i, num_divs = 0)
    {
        num = i*(i+1)/2;
        n = BigInt("1");
        high = num;
        while (high > n)
        {
            //writeln(num, " ", n, " ", num%n);
            if (num%n == 0)
            {
                num_divs += 2;
                high = num / n;
            }
            n++;
        }
        if (num_divs > growing_divs)
        {
            writeln(num_divs);
            growing_divs = num_divs;
        }
        //writeln(num_divs);
        if (num_divs > 500)
        {
            writeln(i);
            break;
        }
    }
        
}
