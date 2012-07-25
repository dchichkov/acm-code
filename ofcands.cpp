#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

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

struct shape {
    point start_p;
    int length;
    string type;
    long r, g, b;
};

/*global variables*/
int num_cases, num_shapes, num_queries;
vector<shape> shapes;
vector<shape> comp_shapes;
const string SQUARE = "SQUARE", CIRCLE = "CIRCLE";
/*global variables*/

bool is_bound_circ(shape s, point q)
{
    double l;
    long x, y, x2, y2;
    x = q.first;
    y = q.second;
    x2 = s.start_p.first;
    y2 = s.start_p.second;
    l = sqrt(((x2-x)*(x2-x))+((y2-y)*(y2-y))); //distance formula
    debug(l, TAB); debug(s.length, endl);
    if (l == (double)s.length) return true;
    return false;
}

bool is_bound_squa(shape s, point q)
{
    if (q.first == s.start_p.first && q.second >= s.start_p.second && q.second <= s.start_p.second + s.length)
        return true;
    else if (q.second == s.start_p.second && q.first >= s.start_p.first && q.first <= s.start_p.first + s.length)
        return true;

    return false;
}

bool is_in_circ(shape s, point q)
{
    double l;
    long x, y, x2, y2;
    x = q.first;
    y = q.second;
    x2 = s.start_p.first;
    y2 = s.start_p.second;
    l = sqrt(((x2-x)*(x2-x))+((y2-y)*(y2-y))); //distance formula
    debug(l, TAB); debug(s.length, endl);
    if (l < (double)s.length) return true;
    return false;
}

bool is_in_squa(shape s, point q)
{
    if (q.first > s.start_p.first && q.second > s.start_p.second &&
        q.first < (s.start_p.first + s.length) && q.second < (s.start_p.second + s.length))
        return true;
    return false;
}

void dump()
{
    //dump data
    for (int i = 0; i < shapes.size(); ++i)
    {
        shape s = shapes[i];
        debug(s.type, endl);
        debug(s.start_p.first, endl);
        debug(s.start_p.second, endl);
        debug(s.length, endl);
        debug(s.r, endl);
        debug(s.g, endl);
        debug(s.b, endl);
    }
}

void getInput()
{
    //get shapes and the number of queriers
    scanf("%d %d", &num_shapes, &num_queries);
    char sh_type[7];
    int px, py, len, r, g, b;
    while (num_shapes-- > 0)
    {
        scanf("%s %d %d %d %d %d %d", sh_type, &px, &py, &len, &r, &g, &b);
        shape s;
        s.type = sh_type;
        s.start_p.first = px;
        s.start_p.second = py;
        s.length = len;
        s.r = r;
        s.g = g;
        s.b = b;
        
        shapes.push_back(s);
    }
}

void process()
{
    //process input
    point q;
    long r = 0, g = 0, b = 0;
    bool done = false;
    while (num_queries-- > 0)
    {
        scanf("%d %d", &q.first, &q.second);
        //check boundaries
        for (vector<shape>::iterator it = shapes.begin(); it != shapes.end(); ++it)
        {
            if (it->type == SQUARE)
                done = is_bound_squa(*it, q);
            else if (it->type == CIRCLE)
                done = is_bound_circ(*it, q);
            if (done) break;
        }
        if (!done)
        {
            for (vector<shape>::iterator it = shapes.begin(); it != shapes.end(); ++it)
            {
                //reuse done for a different purpose, to say yes if point is in an object
                if (it->type == SQUARE)
                    done = is_in_squa(*it, q);
                else if (it->type == CIRCLE)
                    done = is_in_circ(*it, q);

                if (done) comp_shapes.push_back(*it);
            }

            if (comp_shapes.size() == 0) r = g = b = 255; //not in a shape, so white
            else
            {
                for (vector<shape>::iterator it = comp_shapes.begin(); it != comp_shapes.end(); ++it)
                {
                    //average all
                    r += it->r;
                    g += it->g;
                    b += it->b;
                }
                debug(r, TAB); debug(g, TAB); debug(b, TAB); debug(comp_shapes.size()-1, endl);
                r += comp_shapes.size()-1;
                g += comp_shapes.size()-1;
                b += comp_shapes.size()-1;
                debug(r, TAB); debug(g, TAB); debug(b, endl);
                r /= comp_shapes.size();
                g /= comp_shapes.size();
                b /= comp_shapes.size();
            }
        }
        printf("(%ld, %ld, %ld)\n", r, g, b);

        r = g = b = 0;
        comp_shapes.clear();
    }
}

int main()
{
    scanf("%d", &num_cases);
    int count = 0;
    while (num_cases-- > 0)
    {
        ++count;
        printf("Case %d:\n", count);
        getInput();
        //dump();
        process();
        if (num_cases > 0)
            printf("\n");

        //reset
        comp_shapes.clear();
        shapes.clear();
    }

    return 0;
}
