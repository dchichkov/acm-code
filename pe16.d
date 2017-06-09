import std.stdio;
import std.bigint;
import std.format : format;

void main()
{
    BigInt j = BigInt("2");
    j ^^= 1000;
    string str = format("%d", j);
    BigInt total = BigInt("0");
    foreach (int i, char c; str)
    {
        total += BigInt(str[i .. i+1]);
    }
    writeln(total);
}
