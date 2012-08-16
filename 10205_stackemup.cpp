#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <map>


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
map<int, string> cards;
map<int, string> shuffled;
vector<vi> shuffles;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int num_shuffles, num;
    scanf("%d", &num_shuffles);
    REP(i, num_shuffles)
    {
        vi shuffle;
        
        REP(j, 52)
        {
            scanf("%d ", &num);
            shuffle.push_back(num);
        }
        shuffles.push_back(shuffle);
    }
    
    return true;
}

void apply_shuffle(int idx)
{
    REP(i, shuffles[idx].size())
        shuffled[i+1] = cards[shuffles[idx][i]];

    cards = shuffled;
}

void process()
{
    //process input
    char line[10];
    int shuffle_num;
    fgets(line, 10, stdin);
    while (line[0] != '\n')
    {
        sscanf(line, "%d", &shuffle_num);
        apply_shuffle(shuffle_num-1);
        if (fgets(line, 10, stdin) == NULL) break;
    }
    
    for (map<int, string>::iterator it = cards.begin(); it != cards.end(); ++it)
        printf("%s\n", it->second.c_str());
}

int main()
{        
    int nc;
    scanf("%d\n", &nc);
    while (nc-- > 0)
    {
        getInput();
        cards[1] = "2 of Clubs";
        cards[2] = "3 of Clubs";
        cards[3] = "4 of Clubs";
        cards[4] = "5 of Clubs";
        cards[5] = "6 of Clubs";
        cards[6] = "7 of Clubs";
        cards[7] = "8 of Clubs";
        cards[8] = "9 of Clubs";
        cards[9] = "10 of Clubs";
        cards[10] = "Jack of Clubs";
        cards[11] = "Queen of Clubs";
        cards[12] = "King of Clubs";
        cards[13] = "Ace of Clubs";
        cards[14] = "2 of Diamonds";
        cards[15] = "3 of Diamonds";
        cards[16] = "4 of Diamonds";
        cards[17] = "5 of Diamonds";
        cards[18] = "6 of Diamonds";
        cards[19] = "7 of Diamonds";
        cards[20] = "8 of Diamonds";
        cards[21] = "9 of Diamonds";
        cards[22] = "10 of Diamonds";
        cards[23] = "Jack of Diamonds";
        cards[24] = "Queen of Diamonds";
        cards[25] = "King of Diamonds";
        cards[26] = "Ace of Diamonds";
        cards[27] = "2 of Hearts";
        cards[28] = "3 of Hearts";
        cards[29] = "4 of Hearts";
        cards[30] = "5 of Hearts";
        cards[31] = "6 of Hearts";
        cards[32] = "7 of Hearts";
        cards[33] = "8 of Hearts";
        cards[34] = "9 of Hearts";
        cards[35] = "10 of Hearts";
        cards[36] = "Jack of Hearts";
        cards[37] = "Queen of Hearts";
        cards[38] = "King of Hearts";
        cards[39] = "Ace of Hearts";
        cards[40] = "2 of Spades";
        cards[41] = "3 of Spades";
        cards[42] = "4 of Spades";
        cards[43] = "5 of Spades";
        cards[44] = "6 of Spades";
        cards[45] = "7 of Spades";
        cards[46] = "8 of Spades";
        cards[47] = "9 of Spades";
        cards[48] = "10 of Spades";
        cards[49] = "Jack of Spades";
        cards[50] = "Queen of Spades";
        cards[51] = "King of Spades";
        cards[52] = "Ace of Spades";
        process();

        /*output*/


        /*output*/
        if (nc > 0)
            cout << endl;

        shuffles.clear();
    }

    return 0;
}
