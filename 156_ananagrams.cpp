#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
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
vector<multiset<char> > domain;
vector<string> words;
/*global variables*/

void dump()
{
    //dump data
    for (vector<string>::iterator it = words.begin(); it != words.end(); ++it)
        cout << *it << endl;
}

void p(const multiset<char>& s)
{
    for (multiset<char>::iterator it = s.begin(); it != s.end(); ++it)
    {
        printf("%c,", *it);
    }
}

bool getInput()
{
    string line;
    cin >> line;
    while (line != "#")
    {
        words.push_back(line);
        multiset<char> word;
        for (size_t i = 0; i < line.length(); ++i)
            word.insert(tolower(line[i]));
        domain.push_back(word);
        cin >> line;
    }
    //get input
    return true;
}

void process()
{
    //process input
    int i = 0;
    bool unq = true;
    vector<string> words2;
    for (vector<multiset<char> >::iterator it = domain.begin(); it != domain.end(); ++it, ++i)
    {
        unq = true;
        for (vector<multiset<char> >::iterator jt = domain.begin(); jt != domain.end(); ++jt)
        {
            if (it == jt) continue;
            if (*it == *jt)
            {
                unq = false;
            }
            /*else
            {
                p(*it);
                cout << " ";
                p(*jt);
                cout << endl;
                }*/
        }
        if (unq) words2.push_back(words[i]);
    }

    sort(words2.begin(), words2.end());
    for (vector<string>::iterator it = words2.begin(); it != words2.end(); ++it)
        cout << *it << endl;
}

int main()
{
    {
        getInput();
        process();

        /*output*/


        /*output*/
    }

    return 0;
}
