import std.stdio;
import core.stdc.limits;
import std.bigint;

void main()
{
    BigInt n;
    //it's 145 and 40585
    for (int i = 3, t = i; i < INT_MAX; ++i, t = i)
    {
        n = BigInt("0");
        while (t != 0)
        {
            n += fac(t % 10);
            t /= 10;
        }
        if (n == i)
            writeln(n);
    }
}

BigInt fac(int num)
{
    BigInt n = BigInt("1");
    for (int i = 2; i <= num; ++i)
        n *= i;
    return n;
}
