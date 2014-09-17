#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

#define DEBUG  //comment this line to pull out print statements
#ifdef DEBUG
#define TAB '\t'
#define debug(a, end) cout << #a << ": " << a << end
#define dbg(end) end
#else
#define debug(a, end)
#define dbg(end)
#endif

typedef pair<int, int> point;
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
vector<string> words;
map<string, int> numbers;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    string line;
    if (cin.peek() == EOF) return false;
    getline(cin, line);
    string wd;
    stringstream str(line);

    while (str >> wd)
    {
        words.push_back(wd);
    }
    return true;
}

void process()
{
    //process input
    bool is_neg = false;
    if (words[0].compare("negative") == 0) is_neg = true;

    int op = 0;
    int ttl = 0;
    REP(i, words.size())
    {
        if (numbers.find(words[i]) != numbers.end())
        {
            if (i == words.size()-1)
                ttl += op + numbers[words[i]];
            else
                op += numbers[words[i]];
        }
        else
        {
            if (words[i].compare("hundred") == 0)
            {
                if (i+1 < words.size() && words[i+1].compare("thousand") == 0)
                {
                    ttl += op * 100 * 1000;
                    op = 0;
                }
                else if (i+1 < words.size() && words[i+1].compare("million") == 0)
                {
                    ttl += op * 100 * 1000000;
                    op = 0;
                }
                else if (i == words.size()-1)
                    ttl += op*100;
                else
                    op *= 100;
            }
            else if (words[i].compare("thousand") == 0)
            {
                ttl += op * 1000;
                op = 0;
            }
            else if (words[i].compare("million") == 0)
            {
                ttl += op * 1000000;
                op = 0;
            }
        }
               
    }
    printf("%s%d\n", is_neg ? "-" : "", ttl);
}

int main()
{
    numbers["zero"] = 0;
    numbers["one"] = 1;
    numbers["two"] = 2;
    numbers["three"] = 3;
    numbers["four"] = 4;
    numbers["five"] = 5;
    numbers["six"] = 6;
    numbers["seven"] = 7;
    numbers["eight"] = 8;
    numbers["nine"] = 9;
    numbers["ten"] = 10;
    numbers["eleven"] = 11;
    numbers["twelve"] = 12;
    numbers["thirteen"] = 13;
    numbers["fourteen"] = 14;
    numbers["fifteen"] = 15;
    numbers["sixteen"] = 16;
    numbers["seventeen"] = 17;
    numbers["eighteen"] = 18;
    numbers["nineteen"] = 19;
    numbers["twenty"] = 20;
    numbers["thirty"] = 30;
    numbers["forty"] = 40;
    numbers["fifty"] = 50;
    numbers["sixty"] = 60;
    numbers["seventy"] = 70;
    numbers["eighty"] = 80;
    numbers["ninety"] = 90;
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        words.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
