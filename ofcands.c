/**
   Problem: Of Circles and Squares (UVa 10823)
   Developed by Isaac Traxler and Matthew Gavin

 **/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct shape {
    int px, py;
    int length;
    char type[2];
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

typedef unsigned short ushort;

/*global variables*/
int num_cases, num_shapes, num_queries;
struct shape shapes[102];
char line[50];
char* next;
char buf[255];
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

ushort myItoA(ushort num, char *buff)
{ /* FUNCTION myItoA */
    ushort lngth;

    if (10 > num)
    { /* 0-9 */
        buff[0]= num + 0x30;
        buff[1]= 0;
        lngth= 1;
    } /* 0-9 */
    else
        if (100 > num)
        { /* 10 to 99 */
            buff[0]= num / 10 + 0x30;
            buff[1]= num % 10 + 0x30;
            buff[2]= 0;
            lngth=2;
        } /* 10 to 99 */
        else
        { /* 100 to 255 */
            buff[0]= num / 100 + 0x30;
            buff[1]= num / 10  % 10 + 0x30;
            buff[2]= num % 10 + 0x30;
            buff[3]= 0;
            lngth=3;
        } /* 100 to 255 */
    return lngth;
} /* FUNCTION myItoA */

int main()
{
    /*scanf("%d", &num_cases);*/
    fgets(line, 50, stdin);
    num_cases = strtol(line, NULL, 10);
    int count = num_cases;
    ushort offset;
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
                shapes[i].type[0] = line[0];
                shapes[i].type[1] = 0;
                /*shapes[i].type[1] = line[1];
                shapes[i].type[2] = line[2];
                shapes[i].type[3] = line[3];
                shapes[i].type[4] = line[4];
                shapes[i].type[5] = line[5];
                shapes[i].type[6] = 0; */
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
                /*printf("(%d, %d, %d)\n", r, g, b);*/
                
                buf[0]='(';
                offset=myItoA(r, &buf[1])+1;
                buf[offset++] = ',';
                buf[offset++] = ' ';
                offset=offset + myItoA(g, &buf[offset]);
                buf[offset++] = ',';
                buf[offset++] = ' ';
                offset=offset + myItoA(b, &buf[offset]);
                buf[offset++] = ')';
                buf[offset++] = '\n';
                buf[offset] = 0;
                /*puts(buf);*/
                fwrite(buf, sizeof(char), offset, stdout);
                
                r = g = b = 0;
                count = 0;
            }
        }
        if (num_cases > 0)
            fputs("\n", stdout);

    }

    return 0;
}
