//
// Created by rols on 4/6/17.
//

#include <stdio.h>
typedef char STRING[1000];
enum m{ S=1, L=2 } s[2]={ S, L };
int fvir(int n)
{
    int i,j,k=2, x,y, a,b=0, p,p1,p2, t,tt;
    for (y=1; y<=n; y++)
    {
        char tab[1000][10]={0};
        for (t=j=1; j<=y; j++) t<<=1;
        for (x=0; x<y; x++)
        {
            for(tt=i=1; i<=x; i++) tt<<=1;
            for (p1=0; p1<t;)
            {
                for (a=0; a<k; a++)
                {
                    for (p2=0; p2<tt; p2++)
                    { tab[p1][x]=s[a]; p1++; }
                }
            }
        }
        for(x=0; x<t; b+=p==n, x++)
            for(p=i=0; tab[x][i]; p+=tab[x][i++]);
    }
    return (b);
}
main() { printf("%d\n%d", fvir(4), fvir(8)); }