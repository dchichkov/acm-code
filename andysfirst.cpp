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
string unacceptable = " !\"#$%&'()*+,-./0123456789:;<=>?@[\\]^_`{|}~\t\r\n";
/*global variables*/

void splitwords(string word)
{
    int x = 0;
    int y = 0;
    while ((x = word.find_first_not_of(unacceptable, x)) != string::npos)
    {
        y = word.find_first_of(unacceptable, x);
        words.insert(word.substr(x, y-x));
        x = y;
    }
}

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    //char word[250];
    int what = 0;
    string word;
    //while(scanf("%[A-Za-z]%*[0-9\\\(\)\{\}\'\.\,\"\:\;\?\-\! \n$%^&*!@#+=?<>;]", word) != EOF)
    while (cin >> word)
    {
        //if (++what == 5000) break;
        //if (strcmp(word, "") == 0) break;
        //debug(word, TAB);
        REP(i, word.length())
            word[i] = tolower(word[i]);
        /*words.insert(word);
        CL(word, 0);*/
        splitwords(word);
    }
    
    return true;
}

void process()
{   
    for (set<string>::iterator it = words.begin(); it != words.end(); ++it)
        if (it->length() != 0)
            printf("%s\n", it->c_str());       
}

int main()
{
    getInput();
    process();
    return 0;
}
