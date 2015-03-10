/* Class:   CSC 2700 Programming Competitions
 * Prof:    Isaac Traxler
 * Name:    Matthew Gavin
 * Problem: 628 - Passwords
 *
 * Note: You don't need a lot of nasty loops. Just a character array with all your numbers!
 */ 

#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

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
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
vector<string> words;
vector<string> rules;
int num_words;
int num_rules;
string x;
char zeroes[10000000][7];
int maxes[8];
int max_fact;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    scanf(" ");
    if (feof(stdin)) return false;
    //get input
    
    scanf("%d ", &num_words);
    REP(i, num_words)
    {
        getline(cin, x);
        words.push_back(x);
    }
    
    scanf("%d ", &num_rules);
    REP(i, num_rules)
    {
        getline(cin, x);
        rules.push_back(x);
    }
    return true;
}

void fill_upto(int fact)
{
    //pre-generate zeroes
    FOR(i, max_fact, fact)
    {
        zeroes[i][0] = '0' + (i / 1000000);
        zeroes[i][1] = '0' + (i / 100000) % 10;
        zeroes[i][2] = '0' + (i / 10000) % 10;
        zeroes[i][3] = '0' + (i / 1000) % 10;
        zeroes[i][4] = '0' + (i / 100) % 10;
        zeroes[i][5] = '0' + (i / 10) % 10;
        zeroes[i][6] = '0' + (i % 10);
    }
    max_fact = fact;
}

void process()
{
    int z_cnt;
    REP(i, num_rules)
    {
        z_cnt = 0;
        REP(p, rules[i].length())
        {
            if (rules[i][p] == '0')
                z_cnt++;
        }
        
        REP(j, num_words)
        {
            if (maxes[z_cnt-1] > max_fact) fill_upto(maxes[z_cnt-1]);
            for (int k = 0; k < maxes[z_cnt-1]; ++k)
            {
                for (int m = 0, zc = 7-z_cnt; m < rules[i].length(); ++m)
                {
                    if (rules[i][m] == '#')
                        fputs(words[j].c_str(), stdout);
                    else
                    {
                        putchar(zeroes[k][zc++]);
                    }
                }
                fputs("\n", stdout);
            }
        }
    }
    
}

int main()
{
    maxes[0] = 10;
    maxes[1] = 100;
    maxes[2] = 1000;
    maxes[3] = 10000;
    maxes[4] = 100000;
    maxes[5] = 1000000;
    maxes[6] = 10000000;
    max_fact = 0;
    while (getInput())
    {
        fputs("--\n", stdout);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        words.clear();
        rules.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
