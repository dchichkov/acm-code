#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <map>
#include <algorithm>

using namespace std;

#define DEBUG
//#undef DEBUG //uncomment this line to pull out print statements
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
map<char, char> letters;
vector<string> words;
string line;
/*global variables*/

void dump()
{
    //dump data
}

void reset()
{
    for (int i = 0; i < 26; ++i)
        letters[(char)((int)'a'+i)] = '*';

}

bool sort_len(string it, string jt)
{
    return (it.length() < jt.length());
}

bool match_word(string dict_word, string new_line)
{
    
}
bool match_vowels();

void process()
{
    //process input
    reset();
    sort(words.begin(), words.end(), sort_len);
    string new_line(line);
    
}

int main()
{
    int num_words;
    scanf("%d\n", &num_words);
    for (int i = 0; i < num_words; ++i)
    {
        string t;
        cin >> t;
        words.push_back(t);
    }
    cin.ignore(); //skip last new line
    while (getline(cin, line))
    {

        process();

        /*output*/

        cout << line << endl;
        /*output*/
    }
}
