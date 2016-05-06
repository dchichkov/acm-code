import std.stdio : writeln;
import std.bigint;
import std.format : format;

void main()
{
    int i = 3;
    BigInt a = BigInt("1");
    BigInt b = BigInt("1");
    BigInt c;
    for (;; ++i)
    {
        c = b;
        b += a;
        if (format("%d", b).length == 1000)
            break;
        a = c;
    }
    writeln(i);
}
