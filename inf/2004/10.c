//
// Created by rols on 4/6/17.
//

#include <stdio.h>
#include <string.h>
#define MAX 10
#define N(a,b,c) a<b?(a<c?a:c):(b<c?b:c)
int ucz(a, b, c1, c2, c3)
        char *a, *b;
        int c1, c2, c3;
{
    int i,j,k,m;
    int cz[MAX][MAX]={0};
    for (i=1; i<=strlen(a); i++)
        cz[i][0]=cz[i-1][0]+c2;
    for (i=1; i<=strlen(b); i++)
        cz[0][i]=cz[0][i-1]+c1;
    for (i=1; i<=strlen(a); i++)
        for (j=1; j<=strlen(b); j++)
        {
            cz[i][j]=cz[i-1][j-1];
            if (a[i-1]-b[j-1]) cz[i][j]+=c3;
            cz[i][j]=N(cz[i][j],cz[i][j-1]+c1,
                       cz[i-1][j]+c2);
        }
    return (cz[strlen(a)][strlen(b)]);
}
main()
{
    int i;
    i= ucz("IGALO","IGLA",3,2,1);
    printf("%d",i);
}