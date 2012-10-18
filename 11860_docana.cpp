#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

#define DEBUG //comment this line to pull out print statements
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
set<string> words;
map<string, vi> word_found;
/*global variables*/

void dump()
{
    //dump data
    for (vector<string>::iterator it = words.begin(); it != words.end(); ++it)
    {
        cout << *it << endl;
    }
}

void normalize(string& s)
{
    REP(i, s.length())
        if (!isalpha(s[i]))
            s.replace(i, 1, " ");

}

bool getInput()
{
    //get input
    int pos = 0;
    string woyd, word;
    cin >> woyd;
    normalize(woyd);
    istringstream sst(woyd);
    while(woyd != "END")
    {
        if (pos == 11) break;
        if (woyd.find_first_of("abcdefghijklmnopqrstuvwxyzEND") != string::npos)
        {
            sst.clear(); //clear your flags
            while (sst >> word)
            {
                debug(word, TAB); debug(pos, endl);
                words.insert(word);
                word_found[word].push_back(pos++);
            }
        }

        cin >> woyd;
        normalize(woyd);
        sst.str(woyd);
    }

    return true;
}

void process()
{
    //process input
    int x, y;
    
    
    printf("%d %d\n", x, y);
}

int main()
{
    int nc;
    int count = 0;
    scanf("%d\n", &nc);
    while (nc-- > 0)
    {
        printf("Document %d: ", ++count);
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        words.clear();
        word_found.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
