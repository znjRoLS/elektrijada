
#include <stdio.h>
#define X 15
#define Y X/2


void e2012_3()
{
    int xx, yy, p, q, tmp, min;
    static int b[50][50];
    for (p=1; p<=X; p++) b[p][1]=p;
    for (q=1; q<=Y; q++) b[1][q]=q;
    for (xx=2; xx<=X; xx++)
    {
        for (yy=2; yy<=Y; yy++)
        {
            if (xx==yy)
            b[xx][yy]=1;
            else
            {
                min=100;
                for (p=1; p<xx; p++)
                {
                    tmp = b[p][yy] + b[xx-p][yy];
                    if (tmp<min)
                    min = tmp;
                }
                for (q=1; q<yy; q++)
                {
                    tmp = b[xx][q] + b[xx][yy-q];
                    if (tmp<min)
                    min = tmp;
                }
                b[xx][yy] = min;
            }
        }
    }
    printf("%d", b[X][Y]);
}
