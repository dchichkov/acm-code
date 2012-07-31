#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <string>

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
set<string> words;
set<string> invalid_words;

/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    string str;
    int x = 0;
    while (cin >> str)
    {
        x = 0;
        str += ".";
        REP(i, str.length())
            str[i] = tolower(str[i]);
        REP(i, str.length())
        {
            if (!isalpha(str[i]))
            {
                //char c = str[i];
                str.erase(i,1);
                /*if (c == '\'' && str[i-1] == 'n' && str != "cant.")
                {
                    debug(str, endl);
                    words.insert(str.substr(x, i-x-1));
                }
                else*/
                words.insert(str.substr(x, i-x));
                debug(str.substr(x, i-x), TAB);
                x = i;
                //i--;
            }
        }
        if (!x)
            words.insert(str);
        debug(str, endl);
    }
    
    return true;
}

void process()
{
    //process input

    /*for (set<string>::iterator it = invalid_words.begin(); it != invalid_words.end(); ++it)
    {
        set<string>::const_iterator jt;
        jt = words.find(*it);
        if (jt != words.end())
            words.erase(*it);
    }*/

    /*for (set<string>::iterator it = words.begin(); it != words.end(); ++it)
        if (it->length() == 1 && (*it != "a" && *it != "i") || it->length() == 0)
        words.erase(*it);*/
    for (set<string>::iterator it = words.begin(); it != words.end(); ++it)
        if (it->length() == 1)
        {
            REP(i, it->length())
                if (!isalpha(it->at(i)))
                {
                    words.erase(*it);
                    break;
                }
        }
        else if  (it->length() == 0)
            words.erase(*it);

    for (set<string>::iterator it = words.begin(); it != words.end(); ++it)
        printf("%s\n", it->c_str());
            
}

int main()
{
    
    invalid_words.insert("re");
    invalid_words.insert("ve");
    invalid_words.insert("ll");
    invalid_words.insert("em");
    invalid_words.insert("im");
    
    getInput();
    process();
    return 0;
}
