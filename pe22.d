import std.stdio;
import std.algorithm : sort;
import std.array;
import std.bigint;

void main()
{
    File f = File("p022_names.txt");
    string names = f.readln();
    f.close();
    auto a = std.array.split(names, ",");
    foreach (ref string b; a)
    {
        b = b[1 .. $-1];
    }
    sort(a);
    writeln(a.length);
    BigInt n = BigInt("0");
    int t;
    foreach (int i, string x; a)
    {
        t = 0;
        foreach (char c; x)
        {
            t += c-'A'+1;
        }
        n += (t*(i+1));
    }

    writeln(n);

}
