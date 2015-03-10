#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <set>

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

vector<set<int> > winning_sets;

int winning_pos[12][5][5] = {
    {{1,1,1,1,1}, //row 1
     {0,0,0,0,0},
     {0,0,0,0,0},
     {0,0,0,0,0},
     {0,0,0,0,0}},
    {{0,0,0,0,0}, //row 2
     {1,1,1,1,1},
     {0,0,0,0,0},
     {0,0,0,0,0},
     {0,0,0,0,0}},
    {{0,0,0,0,0}, //row 3
     {0,0,0,0,0},
     {1,1,1,1,1},
     {0,0,0,0,0},
     {0,0,0,0,0}},
    {{0,0,0,0,0}, //row 4
     {0,0,0,0,0},
     {0,0,0,0,0},
     {1,1,1,1,1},
     {0,0,0,0,0}},
    {{0,0,0,0,0}, //row 5
     {0,0,0,0,0},
     {0,0,0,0,0},
     {0,0,0,0,0},
     {1,1,1,1,1}},
    {{1,0,0,0,0}, //col 1
     {1,0,0,0,0},
     {1,0,0,0,0},
     {1,0,0,0,0},
     {1,0,0,0,0}},
    {{0,1,0,0,0}, //col 2
     {0,1,0,0,0},
     {0,1,0,0,0},
     {0,1,0,0,0},
     {0,1,0,0,0}},
    {{0,0,1,0,0}, //col 3
     {0,0,1,0,0},
     {0,0,1,0,0},
     {0,0,1,0,0},
     {0,0,1,0,0}},
    {{0,0,0,1,0}, //col 4
     {0,0,0,1,0},
     {0,0,0,1,0},
     {0,0,0,1,0},
     {0,0,0,1,0}},
    {{0,0,0,0,1}, //col 5
     {0,0,0,0,1},
     {0,0,0,0,1},
     {0,0,0,0,1},
     {0,0,0,0,1}},
    {{0,0,0,0,1}, //diag 1
     {0,0,0,1,0},
     {0,0,1,0,0},
     {0,1,0,0,0},
     {1,0,0,0,0}},
    {{1,0,0,0,0}, //diag 2
     {0,1,0,0,0},
     {0,0,1,0,0},
     {0,0,0,1,0},
     {0,0,0,0,1}}
};

bool check_winner(int number_removed)
{
    for (vector<set<int> >::iterator it = winning_sets.begin(); it != winning_sets.end(); ++it)
    {
        /*for (set<int>::iterator jt = it->begin(); jt != it->end(); ++jt)
        {
            printf("%d ", *jt);
        }
        printf("\n");
        
        */
        it->erase(number_removed);
        if (it->size() == 0)
            return true;
    }

    
    return false;
}

void read_card()
{
    int card[5][5];
    memset(card, 0, sizeof(int)*5*5); //zero out
    
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (i == 2 && j == 2) ++j;
            scanf("%d", &card[i][j]);
        }
    }

    //get winning combos
    for (int i = 0; i < 12; ++i)
    {
        set<int> winning_combo;
        for (int j = 0; j < 5; ++j)
        {
            for (int k = 0; k < 5; ++k)
            {
                if (winning_pos[i][j][k] == 1)
                    winning_combo.insert(card[j][k]);
            }
        }
        winning_sets.push_back(winning_combo);  
    }
}

int main()
{
    int num_sets = 0;
    scanf("%d", &num_sets);
    
    while (num_sets-- > 0)
    {
        read_card();
        check_winner(0);
        int num_balls = 0;
        int ball = 0;
        int i;
        for (i = 0; i < 75; ++i)
        {
            num_balls++;
            scanf("%d", &ball);
            if (check_winner(ball))
                break;
        }
        for (;i<74; ++i) //read in the rest of the balls
            scanf("%d", &ball);

        printf("BINGO after %d numbers announced\n", num_balls);

        winning_sets.clear();
    }
    
    return 0;
}

