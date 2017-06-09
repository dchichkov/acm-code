#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>

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
#define REP(i,n) FOR(i,0,(int)n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
char line[10];
map<string, int> wordpos; //instead of doing int -> string... this is simpler for me
                          //tougher on the machine :]
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    scanf("%s ", &line);
    return true;
}

void process()
{
    //process input
    printf("%d\n", wordpos[line]);
}

int main()
{
    //build list
    int counter = 1;
    string prefix("");
    string f1, s2, t3, f4, f5;
    int first, second, third, fourth, fifth;
    //1 and 2
    for (fourth = -1; fourth < 25; ++fourth)
    {
        for (fifth = 0; fifth < 26; ++fifth)
        {
            if (fifth > fourth)
            {
                f5 = 'a' + fifth;

                prefix += f4;
                prefix += f5;
                        
                wordpos[prefix] = counter++;
                        
                prefix = "";
            }
        }
        f4 = 'a'+fourth+1;
    }
    //three
    for (third = 0; third < 24; ++third)
    {
        t3 = 'a'+third;
        for (fourth = third+1; fourth < 25; ++fourth)
        {
            f4 = 'a'+fourth;
            for (fifth = fourth+1; fifth < 26; ++fifth)
            {
                f5 = 'a' + fifth;

                prefix += t3;
                prefix += f4;
                prefix += f5;
                        
                wordpos[prefix] = counter++;
                        
                prefix = "";
            }
        }
    }
    //four
    for (second = 0; second < 23; ++second)
    {
        s2 = 'a'+second;
        for (third = second+1; third < 24; ++third)
        {
            t3 = 'a'+third;
            for (fourth = third+1; fourth < 25; ++fourth)
            {
                f4 = 'a'+fourth;
                for (fifth = fourth+1; fifth < 26; ++fifth)
                {
                    if (fifth <= fourth) continue;
                    f5 = 'a' + fifth;

                    prefix += s2;
                    prefix += t3;
                    prefix += f4;
                    prefix += f5;
                        
                    wordpos[prefix] = counter++;

                    prefix = "";
                }
            }
        }
    }
    //fifth
    for (first = 0; first < 22; ++first)
    {
        f1 = 'a'+first;
        for (second = first+1; second < 23; ++second)
        {
            s2 = 'a'+second;
            for (third = second+1; third < 24; ++third)
            {
                t3 = 'a'+third;
                for (fourth = third+1; fourth < 25; ++fourth)
                {
                    f4 = 'a'+fourth;
                    for (fifth = fourth+1; fifth < 26; ++fifth)
                    {
                        f5 = 'a' + fifth;

                        prefix += f1;
                        prefix += s2;
                        prefix += t3;
                        prefix += f4;
                        prefix += f5;
                        
                        wordpos[prefix] = counter++;

                        prefix = "";
                    }
                }
            }
        }
    }
    
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
