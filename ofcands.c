#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct shape {
    int px, py;
    int length;
    char type[7];
    int r, g, b;
    int ox, oy;
};

#define REP(a, b) for ((a) = 0; (a) < (b); ++(a))

#ifdef DEBUG
#define debug(a, b) printf("%s -> %s %s", #a, a, b);
#define debug2(a, b) printf("%s -> %d %s", #a, a, b);
#define NEWLINE "\n"
#else
#define NEWLINE
#define debug(a, b)
#define debug2(a, b)
#endif


/*global variables*/
int num_cases, num_shapes, num_queries;
struct shape shapes[102];
char line[50];
char* next;
/*global variables*/


void dump()
{
    int i;
    REP(i, num_shapes)
    {
        debug(shapes[i].type, NEWLINE);
        debug2(shapes[i].px, NEWLINE);
        debug2(shapes[i].py, NEWLINE);
        debug2(shapes[i].length, NEWLINE);
        debug2(shapes[i].r, NEWLINE);
        debug2(shapes[i].g, NEWLINE);
        debug2(shapes[i].b, NEWLINE);
    }
}
int main()
{
    /*scanf("%d", &num_cases);*/
    fgets(line, 50, stdin);
    num_cases = strtol(line, NULL, 10);
    int count = num_cases;
    while (num_cases-- > 0)
    {
        printf("Case %d:\n", count-num_cases);
        {
            fgets(line, 50, stdin);
            num_shapes = strtol(line, &next, 10);
            num_queries = strtol(next, &next, 10);
            /*scanf("%d %d", &num_shapes, &num_queries);*/
            int i;
            REP(i, num_shapes)
            {
                fgets(line, 50, stdin);
                debug(line, NEWLINE);
                strcpy(shapes[i].type, strtok(line, " "));
                shapes[i].px = strtol(line+7, &next, 10);
                shapes[i].py = strtol(next, &next, 10);
                shapes[i].length = strtol(next, &next, 10);
                shapes[i].r = strtol(next, &next, 10);
                shapes[i].g = strtol(next, &next, 10);
                shapes[i].b = strtol(next, NULL, 10);
                shapes[i].ox = shapes[i].px+shapes[i].length;
                shapes[i].oy = shapes[i].py+shapes[i].length;
            }
        }
        /*dump();*/
        {
        
            int qx, qy;
            int r = 0, g = 0, b = 0;
            int count = 0;
            int a, c;
            while (num_queries-- > 0)
            {
                /*scanf("%d %d", &qx, &qy);*/
                fgets(line, 50, stdin);
                qx = strtol(line, &next, 10);
                qy = strtol(next, NULL, 10);
                int i;
                REP(i, num_shapes)
                {
                    if (shapes[i].type[0] == 'S')
                    {
                        if ((((qx == shapes[i].px || qx == (shapes[i].ox))
                              && (qy >= shapes[i].py && qy <= (shapes[i].oy))) ||
                             ((qy == shapes[i].py || qy == (shapes[i].oy))
                              && (qx >= shapes[i].px && qx <= (shapes[i].ox)))))
                        {
                            r = g = b = 0;
                            goto end;
                        }
                        else if ((qx > shapes[i].px && qy > shapes[i].py &&
                                  qx < (shapes[i].ox) && qy < (shapes[i].oy)))
                        {
                            ++count;
                            r += shapes[i].r;
                            g += shapes[i].g;
                            b += shapes[i].b;
                        }
                    }
                    else
                    {
                        a = (((shapes[i].px-qx)*(shapes[i].px-qx))
                                +((shapes[i].py-qy)*(shapes[i].py-qy)));
                        c = (shapes[i].length*shapes[i].length);
                        if (a == c)
                        {
                            r = g = b = 0;
                            goto end;
                        }
                        else if (a < c)
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
                    r = ((r<<1)+count)/(count<<1);
                    g = ((g<<1)+count)/(count<<1);
                    b = ((b<<1)+count)/(count<<1);
                }
                else
                    r = g = b = 255;
            end:
                printf("(%d, %d, %d)\n", r, g, b);
                
                r = g = b = 0;
                count = 0;
            }
        }
        if (num_cases > 0)
            fputs("\n", stdout);

    }

    return 0;
}
