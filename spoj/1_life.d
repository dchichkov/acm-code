import std.stdio;

void main(string[] args)
{
    int line;
    while (stdin.readf("%d ", &line) != 0)
    {
        if (line == 42)
            break;
        stdout.writef("%d\n", line);
    }
}
