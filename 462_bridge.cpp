#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>

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
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,(int)n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
enum FACEP { JACK = 1, QUEEN, KING, ACE };
char hand[13][2];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    REP(i, 13)
    {
        REP(j, 2)
        {
            scanf("%c ", &hand[i][j]);
        }
        debug(hand[i][0], TAB); debug(hand[i][1], endl);
    }
    
    return true;
}

char bid()
{
    int total_points = 0;
    char suits[4] = {'S', 'H', 'D', 'C' };

    set<char> stopped_suits;
    //rule 1
    REP(i, 13)
    {
        switch(hand[i][0])
        {
        case 'J':
            total_points += JACK;
            break;
        case 'Q':
            total_points += QUEEN;
            break;
        case 'K':
            total_points += KING;
            break;
        case 'A':
            total_points += ACE;
            stopped_suits.insert(hand[i][1]);
            break;
        }
    }

    //rule 2 , for all kings
    {
        vector<char> kings;
        REP(i, 13)
        {
            if (hand[i][0] == 'K')
                kings.push_back(hand[i][1]);
        }

        bool has_other;
        REP(i, kings.size())
        {
            has_other = false;
            REP(j, 13)
            {
                if (hand[j][0] != 'K' && hand[j][1] == kings[i])
                    has_other = true;
            }
            if (!has_other)
                total_points--;
            else
                stopped_suits.insert(kings[i]);
               
        }
    }

    //rule 3 , for all queens
    {
        vector<char> queens;
        REP(i, 13)
        {
            if (hand[i][0] == 'Q')
                queens.push_back(hand[i][1]);
        }

        int limit;
        REP(i, queens.size())
        {
            limit = 0;
            REP(j, 13)
            {
                if (hand[j][0] != 'Q' && hand[j][1] == queens[i])
                {
                    limit++;
                }
            }
            if (limit < 2)
                total_points--;
            else
                stopped_suits.insert(queens[i]);
        }
    }
    
    //rule 4 , for all jacks
    {
        vector<char> jacks;
        REP(i, 13)
        {
            if (hand[i][0] == 'J')
                jacks.push_back(hand[i][1]);
        }

        int limit;
        REP(i, jacks.size())
        {
            limit = 0;
            REP(j, 13)
            {
                if (hand[j][0] != 'J' && hand[j][1] == jacks[i])
                {
                    limit++;
                }
            }
            if (limit < 3)
                total_points--;
        }
    }

    debug(total_points, TAB); debug(stopped_suits.size(), endl);
    if (total_points > 15 && stopped_suits.size() == 4)
        return 'T';

    //rule 5
    {
        int limit;
        REP(i, 4)
        {
            limit = 0;
            REP(j, 13)
            {
                if (hand[j][1] == suits[i])
                {
                    limit++;
                }
            }
            if (limit == 2)
                total_points++;
        }
    }

    //rule 6
    {
        int limit;
        REP(i, 4)
        {
            limit = 0;
            REP(j, 13)
            {
                if (hand[j][1] == suits[i])
                {
                    limit++;
                }
            }
            if (limit == 1)
                total_points += 2;
        }
    }

    //rule 7;
    {
        int limit;
        REP(i, 4)
        {
            limit = 0;
            REP(j, 13)
            {
                if (hand[j][1] == suits[i])
                {
                    limit++;
                }
            }
            if (limit == 0)
                total_points += 2;
        }
    }
    if (total_points < 14) return 0;

    char ret = 0;
    int totes = 0;
    int mxtotes = 0;
    REP(i, 4)
    {
        totes = 0;
        REP(j, 13)
        {
            if (hand[j][1] == suits[i])
            {
                totes++;
            }
        }
        if (totes > mxtotes)
        {
            mxtotes = totes;
            ret = suits[i];
        }
    }

    return ret;
}

void process()
{
    //process input
    char which_suit;
    bool is_notrump = (which_suit = bid()) == 'T';
    if (is_notrump)
        printf("BID NO-TRUMP");
    else
    {
        if (which_suit != 0)
            printf("BID %c", which_suit);
        else
            printf("PASS");
    }
    puts("");
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        CL2d(hand, 0, 13, 2);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
