import std.stdio;
import std.datetime;

void main()
{
    DateTime date1 = DateTime(1901, 1, 1);
    DateTime date2 = DateTime(2000, 12, 31);
    string[] days = ["Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"];
    int cnt = 0;
    while (date1 < date2)
    {
        date1.add!"months"(1);
        //writeln(date1.toString(), " ", date1.dayOfWeek, " ", days[date1.day]);
        if (date1.dayOfWeek == DayOfWeek.sun)
        {
            cnt++;
        }
    }
    writeln(cnt);
}
