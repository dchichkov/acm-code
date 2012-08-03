#include <cstdio>
#include <cstring>

#define DEBUG
#undef DEBUG //uncomment this line to pull out print statements
#ifdef DEBUG
#define TAB '\t'
#define debug(a, end) cout << #a << ": " << a << end
#else
#define debug(a, end)
#endif

#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))

struct shape {
    int px, py;
    int length;
    char type[7];
    int r, g, b;
};

struct point {
    int x;
    int y;
};

/*global variables*/
int num_cases, num_shapes, num_queries;
shape shapes[102];
/*global variables*/


void dump()
{
    //dump data
    REP(i, num_shapes)
    {
        debug(shapes[i].type, endl);
        debug(shapes[i].px, endl);
        debug(shapes[i].py, endl);
        debug(shapes[i].length, endl);
        debug(shapes[i].r, endl);
        debug(shapes[i].g, endl);
        debug(shapes[i].b, endl);
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
        {
            scanf("%d %d", &num_shapes, &num_queries);
            REP(i, num_shapes)
                scanf("%6s %d %d %d %d %d %d", shapes[i].type,
                      &shapes[i].px,
                      &shapes[i].py,
                      &shapes[i].length,
                      &shapes[i].r,
                      &shapes[i].g,
                      &shapes[i].b);
        }
        //dump();
        {
            //process input
            point q;
            int r = 0, g = 0, b = 0;
            bool done = 1;
            int count = 0;
            int wat1 = 0,
                wat2 = 0;
            while (num_queries-- > 0)
            {
                scanf("%d %d", &q.x, &q.y);
                //check boundaries
                REP(i, num_shapes)
                {
                    wat1 = (((shapes[i].px-q.x)*(shapes[i].px-q.x))
                            +((shapes[i].py-q.y)*(shapes[i].py-q.y)));
                    wat2 = (shapes[i].length*shapes[i].length);
                    
                    if (shapes[i].type[0] == 'S')
                    {
                        if ((((q.x == shapes[i].px || q.x == (shapes[i].px+shapes[i].length))
                              && (q.y >= shapes[i].py && q.y <= (shapes[i].py + shapes[i].length))) ||
                             ((q.y == shapes[i].py || q.y == (shapes[i].py+shapes[i].length))
                              && (q.x >= shapes[i].px && q.x <= (shapes[i].px + shapes[i].length)))))
                        {
                            r = g = b = 0;
                            done = 0;
                            break;
                        }
                        else if ((q.x > shapes[i].px && q.y > shapes[i].py &&
                                  q.x < (shapes[i].px + shapes[i].length) && q.y < (shapes[i].py + shapes[i].length)))
                        {
                            ++count;
                            r += shapes[i].r;
                            g += shapes[i].g;
                            b += shapes[i].b;
                        }
                    }
                    else
                    {
                        if (wat1 == wat2)
                        {
                            r = g = b = 0;
                            done = 0;
                            break;
                        }
                        else if (wat1 < wat2)
                        {
                            ++count;
                            r += shapes[i].r;
                            g += shapes[i].g;
                            b += shapes[i].b;
                        }    
                    }
                    
                }

                if (count)
                {
                    r = (2*r+count)/(2*count);
                    g = (2*g+count)/(2*count);
                    b = (2*b+count)/(2*count);
                }
                else if (done)
                    r = g = b = 255;
               
                printf("(%d, %d, %d)\n", r, g, b);
                
                r = g = b = 0;
                done = 1;
                count = 0;
            }
        }
        if (num_cases > 0)
            fputs("\n", stdout);

    }

    return 0;
}
