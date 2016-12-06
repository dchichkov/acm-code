/* Class:   CSC 2700 Programming Competitions
 * Prof:    Isaac Traxler
 * Name:    Matthew Gavin
 * Problem: 641 - Do The Untwist
 *
 * Note: I spent so long thinking about this problem... and then Isaac went through the sample
 *       input in class and everything made sense to me then. But Isaac had no clue still :\
 */ 

#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

//#define DEBUG  //comment this line to pull out print statements
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
char lv[] = {'_', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
             'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '.'};
int key;
string cipherText;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d ", &key);
    if (key == 0) return false;
    cin >> cipherText;
    return true;
}

void process()
{
    //process input
    string plainText(cipherText);
    int val = 0;

    debug(cipherText, TAB); debug(plainText.length(), endl);
    REP(i, cipherText.length())
    {
        if (cipherText[i] == '_')
            val = 0;
        else if (cipherText[i] == '.')
            val = 27;
        else val = cipherText[i] - 0x60;

        plainText[(i*key)%cipherText.length()] = lv[(val+i)%28];
    }

    cout << plainText << endl;
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
