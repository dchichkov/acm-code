import std.stdio;

ulong[1_000_000] bones;

void main()
{
    ulong longest = 0, n, t;
    for (ulong i = 2; i < 1000000; ++i)
    {
        t = collatz(i);
        if (t > longest)
        {
            n = i;
            longest = t;
        }
        bones[i] = t;
    }
    writeln(n, " ", longest);
}
        
ulong collatz(ulong num)
{
    ulong times = 0;
    scope(failure)
    {
        writeln(num);
    }
    while (num != 1)
    {
        if (num%2 == 0)
            num /= 2;
        else
            num = (3*num)+1;
        times++;
        if (num < 1_000_000 && bones[num]) return times + bones[num];
    }
        
    return times;
}
