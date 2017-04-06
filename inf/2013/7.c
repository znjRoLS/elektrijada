//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#define M 7
#define X 999
int x;
int als(int *s)
{
    int i;
    x++;
    for (i=0; i<M; i++)
        if (!s[i]) return (s[i]);
    return (X);
}
void sp(int c[][M], int *p, int *d)
{
    int s[M]={0};
    int t=0, i, k, dc, sd, nd;
    for (i=0; i<M; i++) d[i]=X;
    s[t]=1; d[0]=0; t=0;
    while (!als(s))
    {
        sd=X; dc=d[t];
        for (i=0; i<M; i++)
        {
            if (!s[i])
            {
                nd=dc+c[t][i];
                if (nd<d[i]) { d[i]=nd; p[i]=t; }
                if (d[i]<sd) { sd=d[i]; k=i; }
            }
        }
        s[t=k]=1;
    }
}
int main()
{
    int c[M][M]= {{X,3,4,7,X,5,X},
                  {3,X,X,6,3,X,8},
                  {4,X,X,X,X,6,X},
                  {7,6,X,X,X,1,6},
                  {X,3,X,X,X,X,7},
                  {5,X,6,1,X,X,6},
                  {X,8,X,6,7,6,X}};
    int i, p[M]={0}, d[M];
    sp(c,p,d);
    printf("%d\n%d", x, d[M-1]);
    return (0);
}