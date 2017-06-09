import std.math : pow;
import std.stdio : writeln;

void main()
{
    int n, tot, tot2 = 0;
    //return;
    for (int i = 2; i < 355000; ++i)
    {
        n = i;
        tot = 0;
        while (n != 0)
        {
            tot += pow(n%10, 5);
            n /= 10;
        }
        if (tot == i)
            tot2 += i;
    }
    writeln(tot2);
}
