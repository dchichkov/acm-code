import std.stdio : writeln;
import std.algorithm : nextPermutation;
import std.string : representation;

void main()
{
    int[] abc = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];
    for (int i = 1; i < 1000000; ++i)
    {
        //nextPermutation(representation(abc));
        nextPermutation(abc);
        //writeln(i, " ", abc);
    }
    writeln(abc);
} 
