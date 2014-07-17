#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <sstream>

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
vector<string> dict;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    string line;
    getline(cin, line);
    while (line != "#")
    {
        dict.push_back(line);
        getline(cin, line);
    }
    return true;
}

void process()
{
    //process input
    string line;
    stringstream st;
    char c;
    vector<char> chrs;
    bool valid;
    getline(cin, line);
    while (line.compare("#") != 0)
    {
        st.str(line);
        while (st >> c)
        {
            chrs.push_back(c);
        }

        int cnt = 0;
        string word;
        REP(i, (int)dict.size())
        {
            word = dict[i];
            UN(word);
            valid = true;
            REP(j, word.length())
            {
                debug(dict[i], TAB); debug(word[j], TAB);
                debug(count(dict[i].begin(), dict[i].end(), word[j]), TAB);
                debug(count(chrs.begin(), chrs.end(), word[j]), endl);
                if (count(dict[i].begin(), dict[i].end(), word[j]) >
                    count(chrs.begin(), chrs.end(), word[j]))
                {
                    valid = false;
                    break;
                }
            }
            if (valid) cnt++;
        }
        printf("%d\n", cnt);
        st.clear();
        chrs.clear();
        getline(cin, line);
    }
}

int main()
{
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
