/**
 * Author: Matthew Gavin
 * Date: 9/21/2012
 * Problem: 10896 Known Plaintext Attack
 * Description: Watch out for the gotchas!
 *
 * Prof. Isaac Traxler
 * Compiled with: g++ 10896_plainatt.cpp -o 10896
 * Compiler: g++ 4.6.1
 */

#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <algorithm>

using namespace std;

#define DEBUG
#undef DEBUG //uncomment this line to pull out print statements
#ifdef DEBUG
#define TAB '\t'
#define debug(a, end) cout << #a << ": " << a << end
#else
#define debug(a, end)
#endif

typedef pair<int, int> point;
typedef long long int64; //for clarity
typedef vector<int> vi; //?
typedef vector<point> vp; //?
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } //change min
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } //change max

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
vector<string> sentence;
string word;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    cin.ignore(); //grab next new line
    //get input
    string line, next;
    getline(cin, line);
    istringstream s(line); // :)
    debug(line, endl);
    while (s >> next) { sentence.push_back(next); }

    cin >> word;
    debug(word, endl);
    return true;
}

void process()
{
    //process input
    string chars;
    for (vector<string>::iterator it = sentence.begin(); it != sentence.end(); ++it)
    {
        debug(*it, endl);
        if (it->length() == word.length())
        {
            int expected_len = word[0] <= it->at(0) ? it->at(0)-word[0] : 26-(word[0]-it->at(0)); //better way?
            debug(expected_len, endl);
            for (int i = 1; i < it->length(); ++i)
            {
                if ((word[i] <= it->at(i) ? it->at(i)-word[i] : 26-(word[i]-it->at(i))) != expected_len) break;
                else if (i == it->length()-1) chars += ('a'+expected_len);
            }
            if (word.length() == 1) chars += ('a'+expected_len); //possible gotcha
        }
    }
    UN(chars); //possible gotcha
    printf("%s\n", chars.c_str());

}

int main()
{
    int nc;
    scanf("%d", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();

        sentence.clear();
    }

    return 0;
}
