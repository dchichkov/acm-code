#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>

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

enum TEAM { Godzilla = 0, MechaGodzilla };

struct monster
{
	int strength;
	TEAM team;
};

struct compare
{
	bool operator()( const monster& a, const monster& b )
	{
		if (a.strength == b.strength) return (a.team < b.team );
		else if (a.strength > b.strength) return true;
		else return false;
	}
};

/*global variables*/
priority_queue<monster, vector<monster>, compare> battle;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
	int G, M;
	scanf("%d %d", &G, &M);

	debug(G, TAB); debug(M, endl);
	monster a;
	a.team = Godzilla;
	REP(i, G)
	{
		scanf("%d", &a.strength);
		battle.push(a);
	}

	a.team = MechaGodzilla;
	REP(i, M)
	{
		scanf("%d", &a.strength);
		battle.push(a);
	}
	
	
    return true;
}

void process()
{
    //process input
	while (battle.size() != 1)
	{
		//const monster& d = battle.top();
		//printf("%d: %s\n", d.strength, d.team ? "MechaGodzilla" : "Godzilla");
		battle.pop();
	}
	const monster& d = battle.top();
	printf("%s\n", d.team ? "MechaGodzilla" : "Godzilla");
}

int main()
{
	int nc;
	scanf("%d\n\n", &nc);
    while (nc-- > 0)
    {
		getInput();
        process();

        /*output*/

		while (!battle.empty())
			battle.pop();
        /*output*/
    }

    return 0;
}
