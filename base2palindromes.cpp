#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <bitset>
#include <algorithm>

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
typedef pair<int, vector<int> > bit_factors;
//.first = # bits
//.second = factor
vector<bit_factors> factors;

vector<int> ans;

int num;
/*global variables*/

void dump()
{
    //dump data
}

void inttobin(int n)
{
	int bits = sizeof(n)*8;
	int check_bit = 1;
	string bit_string;
	for (int i = 0; i < bits; ++i)
	{
		bit_string.insert(0, (n & (check_bit << i)) ? "1" : "0");
	}
	cout << bit_string << endl;
}

void precompute()
{
	bit_factors one, two;
	one.first = 1;
	one.second.push_back(1);
	two.first = 2;
	two.second.push_back(3);

	factors.push_back(one);
	factors.push_back(two);

	int shft = 0;
	
	FOR(i, 3, 31)
	{
		//if (i%2 == 0)
		{
			bit_factors even_bits;
			even_bits.first = i;
			int base = 1;
			base <<= i-1;
			base += 1;
			even_bits.second.push_back(base);
			for ( size_t it = (i%2) ? 0 : 1; it < factors.size(); it += 2)
			{
				debug(it, TAB);
				debug(i, TAB); debug(factors[it].first, TAB);
				shft = (i - factors[it].first) / 2;
				debug(shft, endl);
				for ( vi::iterator jt = factors[it].second.begin(); jt != factors[it].second.end(); ++jt)
				{
					//inttobin((base | ((*jt) << shft)));
					debug(*jt, TAB); debug((base | ((*jt) << shft)), endl);
					even_bits.second.push_back(base | ((*jt) << shft));
				}
			}
			factors.push_back(even_bits);
		}
	}
}

bool getInput()
{
    //get input
    if (scanf("%d", &num) == EOF) return false;
    return true;
}

void process()
{
    //process input
    printf("%d\n", ans[num-1]);
}

int main()
{

    precompute();

	{
		for (vector<bit_factors>::iterator it = factors.begin(); it != factors.end(); ++it)
			for (vi::iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
				ans.push_back(*jt);
	}
	sort(ans.begin(), ans.end());

    bool moreToDo;
    while (moreToDo = getInput())
    {

        process();

        /*output*/


        /*output*/
    }

    return 0;
}
